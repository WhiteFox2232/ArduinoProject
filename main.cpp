#include <Arduino.h>
#include "arduino.h"

// init variable here :
#define buttonPin 2
#define ledPin 12

#define buttonPin2 3
#define ledPin2 13

// verification detection
bool auth;
bool auth2;

// Interuption here :
// 1
void pin_ISR() {
    auth2 = false;
    auth = true;
}
// 2
void pin_ISR2() {
    auth = false;
    auth2 = true;
}

// Setup pin
void setup() {
    pinMode(ledPin, OUTPUT);
    pinMode(buttonPin, INPUT);

    pinMode(ledPin2, OUTPUT);
    pinMode(buttonPin2, INPUT);

    attachInterrupt(0, pin_ISR, RISING);
    attachInterrupt(1, pin_ISR2, RISING);

    auth = false;
    auth2 = false;
}

void loop() {
    int i = 0;
    int j = 0;

    if(auth == true) {
        while(auth == true && i < 100){
            digitalWrite(ledPin, HIGH);
            delay(100);
            i++;
        }
        digitalWrite(ledPin, LOW);
        auth = false;
    }

    if(auth2 == true) {
        while(auth2 == true && j < 100){
            digitalWrite(ledPin2, HIGH);
            delay(100);
            j++;
        }
        digitalWrite(ledPin2, LOW);
        auth2 = false;
    }
}
