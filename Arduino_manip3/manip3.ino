#define bp1 2
#define led1 11
#define relache true
#define presse false
#define allume true
#define eteint false

boolean Mem = false;
boolean MemLed;

void setup()
{
  pinMode(bp1, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
  digitalWrite(led1,HIGH);
  MemLed = 0;
  Serial.begin(9600);
}

void loop()
{
  boolean EtatBP;
  EtatBP = digitalRead(bp1);

  if(EtatBP == presse && Mem == false) {
    Serial.print("^");
    delay(15);
    Mem = true;
    if (MemLed == eteint)
    {
      digitalWrite(led1,LOW);
      MemLed = allume;
    }
    else if (MemLed == allume)
    {
      digitalWrite(led1,HIGH);
      MemLed = eteint;
    }
  }
  if (EtatBP == relache)
  {
    Serial.print(".");
    Mem = false;
    delay(15);
  }
}
