#define led1 11
#define ledOn true
#define ledOff false

boolean ledState;

void setup() {
    pinMode(led1, OUTPUT);
    ledState = ledOff;
}

void loop() {
    ledState = digitalRead(led1);

    if (ledState == ledOff)
        digitalWrite(led1,HIGH);
    else if (ledState == ledOn)
        digitalWrite(led1,LOW);
    delay (200);
}