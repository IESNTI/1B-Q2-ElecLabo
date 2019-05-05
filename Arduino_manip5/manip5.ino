#define potentiometer A5
#define led1 11

unsigned int potentiometerValue;
unsigned int brightness;

void setup() {
    pinMode(potentiometer, INPUT);
    pinMode(led1, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    potentiometerValue = analogRead(potentiometer);
    brightness = map(potentiometerValue, 0, 1023, 0, 255);
    Serial.println(brightness);
    analogWrite(led1, brightness);

    delay(50);
}
