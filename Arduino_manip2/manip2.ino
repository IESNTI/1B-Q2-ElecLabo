//const char bp1 = 2;
#define bp1 2
#define led1 12

void setup()
{
  pinMode(bp1, INPUT_PULLUP);          // sets the digital pin 13 as output
  pinMode(led1, OUTPUT);
}

void loop()
{
  boolean Etatbp1;
  Etatbp1 = digitalRead(bp1);
  if(Etatbp1)
    digitalWrite(led1,HIGH);
  else
    digitalWrite(led1,LOW);
}
