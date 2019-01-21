int RMP = 6;
int RMN = 7;
int LMP = 11;
int LMN = 10;

void setup()
{
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(17, INPUT);
  pinMode(RMP, OUTPUT);
  pinMode(RMN, OUTPUT);
  pinMode(LMP, OUTPUT);
  pinMode(LMN, OUTPUT);
  digitalWrite(14, LOW);
  digitalWrite(15, HIGH);  
  Serial.begin(9600);
}

void loop()
{
  int key = 1;
  if(pulseIn(17, LOW) > 2200)
  {
    for(int i = 0; i < 7; ++i)
    {
      if(pulseIn(17, LOW) > 1000)
      {
        key = key + (1<<i);
      }
    }      
  }
  if(key == 117)    //FORWARD
  {
    digitalWrite(RMP, HIGH);
    digitalWrite(RMN, LOW);
    digitalWrite(LMP, LOW);
    digitalWrite(LMN, HIGH);
  }
  if(key == 53)    //LEFT
  {
    digitalWrite(RMP, HIGH);
    digitalWrite(RMN, LOW);
    digitalWrite(LMP, LOW);
    digitalWrite(LMN, LOW);
  }
  if(key == 52)    //RIGHT
  {
    digitalWrite(RMP, LOW);
    digitalWrite(RMN, LOW);
    digitalWrite(LMP, LOW);
    digitalWrite(LMN, HIGH);
  }
  if(key == 118)    //BACKWARD
  {
    digitalWrite(RMP, LOW);
    digitalWrite(RMN, HIGH);
    digitalWrite(LMP, HIGH);
    digitalWrite(LMN, LOW);
  }
  if(key == 102)
  {
    digitalWrite(RMP, LOW);
    digitalWrite(RMN, LOW);
    digitalWrite(LMP, LOW);
    digitalWrite(LMN, LOW);
  }
}

