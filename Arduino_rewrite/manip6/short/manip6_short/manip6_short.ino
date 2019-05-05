#define led1 11

void setup() {
    pinMode(led1, OUTPUT);
}

void loop() {
    digitalWrite(led1,digitalRead(led1) ? LOW: HIGH);
    delay (200);
}
