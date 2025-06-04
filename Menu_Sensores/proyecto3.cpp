#include "proyecto3.h"


void proyecto3_setup() {
  Serial.begin(9600);             // Inicializamos la comunicación
  pinMode(Trigger, OUTPUT);       // Pin Trigger como salida
  pinMode(Echo, INPUT);           // Pin Echo como entrada
  pinMode(pinLed, OUTPUT);        // LED como salida
  pinMode(pinBuzzer, OUTPUT);     // Buzzer como salida
  digitalWrite(Trigger, LOW);     // Inicializamos el Trigger con 0
  pinMode(Shock, INPUT);          // pin de el sensor de shock 
}