#include <Tempo.h>
#define led1 11
#define led2 10

Tempo ledTime1(1000, DELAY_ON);
Tempo ledTime2(1100, DELAY_ON);

boolean led1State = 0;
boolean led2State = 0;

void setup() {
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    Serial.begin(9600);
    ledTime1.restart();
    ledTime2.restart();
}

void loop() {

    if (ledTime1.ison() == 1) {
        led1State = !led1State;
        digitalWrite(led1, led1State);
        ledTime1.restart();
    }
    if (ledTime2.ison() == 1) {
        led2State = !led2State;
        digitalWrite(led2, led2State);
        ledTime2.restart();
    }
}