#include "proyecto3.h"


void proyecto3Setup() {
  Serial.begin(9600);             // Inicializamos la comunicación
  pinMode(pinLed, OUTPUT);        // LED como salida
  pinMode(pinBuzzer, OUTPUT);     // Buzzer como salida
  pinMode(Shock, INPUT);          // pin de el sensor de shock 
}

void proyecto3(){
  int val = digitalRead(Shock); // Leemos el estado del sensor de shock
  if(val == HIGH) { // cuando el sensor detecta una señal
    digitalWrite(pinLed, LOW);
    digitalWrite(pinBuzzer, LOW);
  } else {
    digitalWrite(pinLed, HIGH);
    digitalWrite(pinBuzzer, HIGH);
  }
}

void resetProyecto3(){
  digitalwrite(pinLed,LOW);
  digitalwrite(pinBuzzer, LOw);
  digitalwrite(Shock, LOW);
}