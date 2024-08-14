#include <Servo.h>

Servo pumprotator;

int pum1=6,pum2=7,p1=8,p2=9,p3=10,p4=11,sensorValue0,sensorValuem90,sensorValue90,most,pos=0;
  // l,h anticlockwise,back
  
void setup() { 
  Serial.begin(9600);
  pumprotator.attach(12);
  pinMode(p1,OUTPUT);
  pinMode(p2,OUTPUT);
  pinMode(p3,OUTPUT);
  pinMode(p4,OUTPUT);
}
void stop()
{
    digitalWrite(p1,LOW);
    digitalWrite(p2,LOW);
    digitalWrite(p3,LOW);
    digitalWrite(p4,LOW);
}
void right()
{
    digitalWrite(p1,HIGH);
    digitalWrite(p2,LOW);
    digitalWrite(p3,LOW);
    digitalWrite(p4,HIGH);
}
void forward()
{
    digitalWrite(p1,HIGH);
    digitalWrite(p2,LOW);
    digitalWrite(p3,HIGH);
    digitalWrite(p4,LOW);
}
void back()
{
    digitalWrite(p1,LOW);
    digitalWrite(p2,HIGH);
    digitalWrite(p3,LOW);
    digitalWrite(p4,HIGH);
}
void left()
{
    digitalWrite(p1,LOW);
    digitalWrite(p2,HIGH);
    digitalWrite(p3,HIGH);
    digitalWrite(p4,LOW);
}
void loop()
{
     sensorValue0= analogRead(A2);
     sensorValue90=analogRead(A3);
     sensorValuem90=analogRead(A4);
     Serial.println(sensorValue0);
     Serial.println(sensorValuem90);
     Serial.println(sensorValue90);
     most=max(sensorValue90,sensorValue0);
     most=max(most,sensorValuem90);
     if(most>100)
     {
        if(most>400)
        {
          stop();
          digitalWrite(pum1,HIGH);
          digitalWrite(pum2,LOW);
        }
        else
        {
          if(most==sensorValue0)
          {
            forward();
          }
          if(most==sensorValuem90)
          {
              left();
          }
          if(most==sensorValue90)
          {
            right();
          }
        }
     }
     else
     {
        stop();
     }
     delay(200);
}
