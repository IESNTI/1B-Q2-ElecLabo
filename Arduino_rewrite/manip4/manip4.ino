#define button1 2
#define led1 11
#define pressed false
#define released true
#define ledOn true
#define ledOff false

boolean saveButtonState;
boolean buttonState;
boolean ledState;
boolean brightnessUp;
int brightness;

void setup() {
    pinMode(button1, INPUT_PULLUP);
    pinMode(led1, OUTPUT);
    saveButtonState = released;
    ledState = ledOff;
    brightness = 0;
    brightnessUp = true;
    Serial.begin(9600);
}

void loop() {
    buttonState = digitalRead(button1);

    if (buttonState == pressed && saveButtonState == released) {
        // Serial.print("^");
        saveButtonState = pressed;
        while (digitalRead(button1) == pressed) {
            delay(5);
            analogWrite(led1, brightness);
            if (brightness < 255 && brightnessUp == true) {
                brightness++;
            } else if (brightness > 0 && brightnessUp == false) {
                brightness--;
            } else if (brightness == 255 || brightness == 0) {
                brightnessUp = !brightnessUp;
            }
            Serial.println(brightness);
        }
    } else if (buttonState == released) {
        // Serial.print(".");
        saveButtonState = released;
    }

    delay(50);
}