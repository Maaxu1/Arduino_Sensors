#include "proyecto2.h"

void proyecto2_setup() {
  pinMode(Trigger, OUTPUT);       // Pin Trigger como salida
  pinMode(Echo, INPUT);           // Pin Echo como entrada
  pinMode(pinLed, OUTPUT);        // LED como salida
  pinMode(pinBuzzer, OUTPUT);     // Buzzer como salida
  digitalWrite(Trigger, LOW);     // Inicializamos el Trigger con 0
  pinMode(Shock, INPUT);          // pin de el sensor de shock 
}