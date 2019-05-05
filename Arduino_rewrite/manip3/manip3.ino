#define button1 2
#define led1 11
#define pressed false
#define released true
#define ledOn true
#define ledOff false

boolean saveButtonState;
boolean buttonState;
boolean ledState;

void setup() {
    pinMode(button1, INPUT_PULLUP);
    pinMode(led1, OUTPUT);
    saveButtonState = released;
    ledState = ledOff;
    Serial.begin(9600);
}

void loop() {
    buttonState = digitalRead(button1);

    if (buttonState == pressed && saveButtonState == released) {
        Serial.print("^");
        saveButtonState = pressed;
        digitalWrite(led1, ledOn);
        digitalWrite(led1, ledOff);
        if (ledState == ledOff) {
            digitalWrite(led1, ledOn);
            ledState = ledOn;
        } else if (ledState == ledOn) {
            digitalWrite(led1, ledOff);
            ledState = ledOff;
        }
    } else if (buttonState == released) {
        Serial.print(".");
        saveButtonState = released;
    }

    delay(50);
}