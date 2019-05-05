#define led 7

void setup() {
    pinMode(led, OUTPUT);
}

void loop() {
    int brightness = map(analogRead(A0), 800, 0, 0, 100);
    Serial.println(brightness);
    if (brightness >= 0 && brightness < 55)
        digitalWrite(led,LOW);
    else if (brightness > 65)
        digitalWrite(led,HIGH);
}
