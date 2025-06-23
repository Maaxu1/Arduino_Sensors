#include "proyecto4.h"
#include "globalSlave.h"
#include <Arduino.h>

void proyecto4Setup() {
  pinMode(pinLed, OUTPUT);
  pinMode(relay, OUTPUT);
  pinMode(analogFlamaPin, INPUT);
  pinMode(pinBuzzer,OUTPUT);
}

int proyecto4() {
  int analogFlamaVal = analogRead(analogFlamaPin);
  if (analogFlamaVal == HIGH) {
    digitalWrite(pinLed, HIGH);
    digitalWrite(pinBuzzer, HIGH);
    delay(100);
    digitalWrite(relay, HIGH);
  } else {
    digitalWrite(pinLed, LOW);
    digitalWrite(pinBuzzer, LOW);
    digitalWrite(relay, LOW);
    delay(100);
  }

  return analogFlamaVal;
}

void proyecto4Reset() {
    digitalWrite(pinLed, LOW);
    digitalWrite(relay , LOW);
    digitalWrite(pinBuzzer,LOW);
}
