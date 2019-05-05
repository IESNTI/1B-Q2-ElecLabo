#define led 3

void setup() {
    pinMode(led, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    int brightness = map(analogRead(A0), 800, 200, 0, 255);
    int percent = map(analogRead(A0), 800, 200, 0, 100);
    Serial.println(brightness);
    analogWrite(led,brightness);
    if (brightness <= 0)
        analogWrite(led, 0);
    else if (brightness >= 255)
        analogWrite(led, 255);
    if (brightness > 0 && brightness < 55) {
        analogWrite(led, brightness);
    }
    else if (brightness > 65) {
        analogWrite(led, brightness);
    }
    delay(100);
}
