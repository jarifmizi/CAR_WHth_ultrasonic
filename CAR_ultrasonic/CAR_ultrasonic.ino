#include <AFMotor.h>
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);




int  trigpin=A0;
int echoPin=A1;
float distance;
float duration;
void setup()
{                          
  pinMode(trigpin,OUTPUT);
  pinMode(echoPin,INPUT);
  Serial.begin(9600);
}
void loop()
{
  digitalWrite(trigpin,LOW);
  delay(2);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin ,LOW);
  duration=pulseIn(echoPin,HIGH);
  distance=(duration*0.034)/2 ;
  Serial.println(distance);
  motor1.setSpeed(200);
  motor1.run(FORWARD);
  delay(1000);
  if(distance<=5)
  {
     motor1.setSpeed(100);
     motor2.setSpeed(50);
     motor2.run(FORWARD);
     delay(10);
     motor2.run(RELEASE);
     delay(100);
     motor2.run(BACKWARD);
     delay(10);
     motor2.run(RELEASE);
     delay(100);
     motor2.run(FORWARD);
     delay(10);
     motor2.run(RELEASE);
     motor1.setSpeed(200);
     }
}
