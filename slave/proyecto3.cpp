#include "proyecto3.h"
#include "globalSlave.h"
#include <Arduino.h>

void proyecto3Setup() {
  pinMode(pinLed, OUTPUT);        // LED como salida
  pinMode(pinBuzzer, OUTPUT);     // Buzzer como salida
  pinMode(Shock, INPUT);          // pin de el sensor de shock 
}

int proyecto3() {
  int val = digitalRead(Shock); // Leemos el estado del sensor de shock
  
  if (val == HIGH) { // Cuando el sensor detecta una señal
    digitalWrite(pinLed, LOW);
    digitalWrite(pinBuzzer, LOW);
    delay(100);
  } else {
    digitalWrite(pinLed, HIGH);
    digitalWrite(pinBuzzer, HIGH);
  }

  return val;
}

void proyecto3Reset() {
  digitalWrite(pinLed,LOW);
  digitalWrite(pinBuzzer, LOW);
  digitalWrite(Shock, LOW);
}