// const char bp1 = 2;
#define bp1 2
#define led1 11

boolean Mem = 0;
boolean MemLed;
unsigned char brightness = 255;

void setup() {
    pinMode(bp1, INPUT_PULLUP);
    pinMode(led1, OUTPUT);
    digitalWrite(led1, HIGH);
    MemLed = 0;
    Serial.begin(9600);
}

void loop() {
    boolean EtatBP;
    EtatBP = digitalRead(bp1);

    if (EtatBP == 0 && Mem == 0) {
        Serial.println("BP On");
        delay(15);
        Mem = 1;
        if (MemLed == 0) {
            while (digitalRead(bp1) == 0) {
                delay(5);
                if (brightness > 0)
                    brightness--;
                analogWrite(led1, brightness);
            }
            // digitalWrite(led1,LOW);
            MemLed = 1;
        } else if (MemLed == 1) {
            while (digitalRead(bp1) == 0) {
                delay(5);
                if (brightness < 255)
                    brightness++;
                analogWrite(led1, brightness);
            }
            // digitalWrite(led1,HIGH);
            MemLed = 0;
        }
    }
    if (EtatBP == 1) {
        Serial.println("BP Off");
        Mem = 0;
        delay(15);
    }
}
