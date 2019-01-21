/*

 The circuit:
 analog 0: accelerometer self test
 analog 1: z-axis
 analog 2: y-axis
 analog 3: x-axis
 analog 4: ground
 analog 5: vcc

*/

// these constants describe the pins. They won't change:
#include<Servo.h>

const int groundpin = 18;             // analog input pin 4 -- ground
const int powerpin = 19;              // analog input pin 5 -- voltage

Servo servox;
Servo servoy;
Servo servoz;
Servo servog;

int posx = 90;
int posy = 90;
int posz = 40;
int posg = 0;

int x = A3;
int y = A2;
int z = A1;

int valx = 0;
int valy = 0;
int valz = 0;

void setup()
{
  // initialize the serial communications:
  
  // Provide ground and power by using the analog inputs as normal
  // digital pins.  This makes it possible to directly connect the
  // breakout board to the Arduino.  If you use the normal 5V and
  // GND pins on the Arduino, you can remove these lines.
  pinMode(groundpin, OUTPUT);
  pinMode(powerpin, OUTPUT);
  digitalWrite(groundpin, LOW); 
  digitalWrite(powerpin, HIGH);
  
  servox.attach(9);
  servoy.attach(10);
  servoz.attach(11);
  servog.attach(6);
  
  servox.write(90);
  servoy.write(90);
  servoz.write(40);
  servog.write(0);
  Serial.begin(9600);
}

void loop()
{
  valx = analogRead(x);
  valy = analogRead(y);
  valz = analogRead(z);

  // print the sensor values:
  Serial.print(analogRead(x));
  // print a tab between values:
  Serial.print("\t");
  Serial.print(analogRead(y));
  // print a tab between values:
  Serial.print("\t");
  Serial.print(analogRead(z));
  Serial.println();
  // delay before next reading:
  delay(35);
  
  if((valx>270)&&(valx<315)&&(valy>320)&&(valy<350))
  {
    posx--;
    servox.write(posx);
  }
  if((valx>375)&&(valx<415)&&(valy>320)&&(valy<350))
  {
    posx++;
    servox.write(posx);
  }
  if((valx>320)&&(valx<350)&&(valy>260)&&(valy<300))
  {
    posy++;
    servoy.write(posy);
  }
  if((valx>320)&&(valx<360)&&(valy>370)&&(valy<400))
  {
    posy--;
    servoy.write(posy);
  }
  if(valz<330)
  {
    servog.write(180);
  }
  if(valz>350)
  {
    servog.write(0);
  }
  if((valx>290)&&(valx<315)&&(valy>305)&&(valy<330))
  {
    posz++;
    servoz.write(posz);
  }
  if((valx>350)&&(valx<380)&&(valy>305)&&(valy<330))
  {
    posz--;
    servoz.write(posz);
  }
}
