#include<Servo.h>
Servo servo1;
Servo servo2;
Servo servo3;

int a = A0;
int b = A1;
int c = A2;

int val1 = 0;
int val2 = 0;
int val3 = 0;

void setup()
{
  servo1.attach(9);
  servo1.attach(10);
  servo1.attach(11);
  
  servo1.write(0);
  servo2.write(0);
  servo3.write(0);
  
  Serial.begin(9600);
}

void loop()
{
  val1 = analogRead(a);
  val2 = analogRead(b);
  val3 = analogRead(c);
  
  if(val1 < 40)
  {
    servo1.write(180);
    delay(3);
  }
  
  if(val1 > 200)
  {
    servo1.write(0);
    delay(3);
  }
  
  if(val2 < 40)
  {
    servo2.write(180);
    delay(3);
  }
  
  if(val2 > 200)
  {
    servo2.write(0);
    delay(3);
  }
  
  if(val3 < 40)
  {
    servo3.write(180);
    delay(3);
  }
  
  if(val3 > 200)
  {
    servo3.write(0);
    delay(3);
  }
}
