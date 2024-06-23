
#include <Arduino.h>
#include "pitches.hpp"

#define SWITCH_TOP PB11
#define SWITCH_BOT PB10
#define SPEAKER PB9
#define LED_TOP PA1
#define LED_BOT PA2
#define eighth 200
#define TIME_WAIT 30000

// GLOBALS //
unsigned long startTime;

void setup() 
{
    pinMode(SWITCH_TOP, INPUT);
    pinMode(SWITCH_BOT, INPUT);
    pinMode(LED_TOP, OUTPUT);
    pinMode(LED_BOT, OUTPUT);
}

void playLick()
{
    delay(500);
    tone(SPEAKER, NOTE_D5);
    delay(eighth);
    noTone(SPEAKER);
    tone(SPEAKER,NOTE_E5);
    delay(eighth);
    noTone(SPEAKER);
    tone(SPEAKER, NOTE_F5);
    delay(eighth);
    noTone(SPEAKER);
    tone(SPEAKER, NOTE_G5);
    delay(eighth);
    noTone(SPEAKER);

    tone(SPEAKER, NOTE_E5);
    delay(2*eighth);
    noTone(SPEAKER);

    tone(SPEAKER, NOTE_C5);
    delay(eighth);
    noTone(SPEAKER);

    tone(SPEAKER, NOTE_D5);
    delay(5*eighth);
    noTone(SPEAKER);
}

void playFurElise()
{
    delay(500);
    tone(SPEAKER, NOTE_E5);
    delay(eighth);
    noTone(SPEAKER);
    tone(SPEAKER, NOTE_DS5);
    delay(eighth);
    noTone(SPEAKER);
    tone(SPEAKER, NOTE_E5);
    delay(eighth);
    noTone(SPEAKER);
    tone(SPEAKER, NOTE_DS5);
    delay(eighth);
    noTone(SPEAKER);
    tone(SPEAKER, NOTE_E5);
    delay(eighth);
    noTone(SPEAKER);
    tone(SPEAKER, NOTE_B4);
    delay(eighth);
    noTone(SPEAKER);
    tone(SPEAKER, NOTE_D5);
    delay(eighth);
    noTone(SPEAKER);
    tone(SPEAKER, NOTE_C5);
    delay(eighth);
    noTone(SPEAKER);
    tone(SPEAKER, NOTE_A4);
    delay(5*eighth);
    noTone(SPEAKER);
}

void loop()
{
    if (digitalRead(SWITCH_TOP) == 1 && digitalRead(SWITCH_BOT) == 1) {
        // we're good
        startTime = millis();
        digitalWrite(LED_TOP,LOW);
        digitalWrite(LED_BOT,LOW);

    } else if (digitalRead(SWITCH_TOP) == 0) {
        digitalWrite(LED_TOP, HIGH);
        if (millis() - startTime > TIME_WAIT) {
            playLick();
            startTime += 10000; // wait some time before chirping again
        }
    } else if (digitalRead(SWITCH_BOT) == 0) {
        digitalWrite(LED_BOT, HIGH);
        if (millis() - startTime > TIME_WAIT) {
            playFurElise();
            startTime += 10000;
        }
    }
}
