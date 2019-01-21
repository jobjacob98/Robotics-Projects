void setup()
{
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  int x = Serial.read();
  if(x == 1)
  {
    digitalWrite(5, HIGH);
  }
  else if(x == 5)
  {
    digitalWrite(5, LOW);
  }
  if(x == 2)
  {
    digitalWrite(6, HIGH);
  }
  else if(x == 6)
  {
    digitalWrite(6, LOW);
  }
  if(x == 3)
  {
    digitalWrite(7, HIGH);
  }
  else if(x == 7)
  {
    digitalWrite(7, LOW);
  }  
}
