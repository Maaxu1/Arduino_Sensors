#include "globals.h"
#include "proyecto2.h"

void proyecto2_setup() {
  pinMode(Trigger, OUTPUT);       // Pin Trigger como salida
  pinMode(Echo, INPUT);           // Pin Echo como entrada
  pinMode(pinLed, OUTPUT);        // LED como salida
  pinMode(pinBuzzer, OUTPUT);     // Buzzer como salida
  digitalWrite(Trigger, LOW);     // Inicializamos el Trigger con 0
  pinMode(Shock, INPUT);          // pin de el sensor de shock 
}

// Función para manejar el sensor de proximidad
void proyecto2() {

  long t;
  long d;

  // Generamos el pulso de Trigger
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);         
  digitalWrite(Trigger, LOW);

  // Leemos el tiempo de respuesta del Echo
  t = pulseIn(Echo, HIGH);       
  d = t / 59;                     // Convertimos el tiempo a distancia (cm)

  Serial.print("Distancia: ");
  Serial.print(d);
  Serial.println(" cm");

  // Si la distancia es menor a 10 cm, encendemos LED y buzzer intermitente
  if (d < 10) {
    digitalWrite(pinLed, HIGH);
    
    // Buzzer pausado (intermitente)
    digitalWrite(pinBuzzer, HIGH);
    delay(100);
    digitalWrite(pinBuzzer, LOW);
    delay(100);
  } else {
    // Apagar LED y buzzer si no hay proximidad
    digitalWrite(pinLed, LOW);
    digitalWrite(pinBuzzer, LOW);
  }
  
  delay(100); // Pausa antes de la siguiente lectura
}

void proyecto2_reset() {
  digitalWrite(Trigger, LOW);
  digitalWrite(Echo, LOW);
  digitalWrite(pinLed, LOW);
  digitalWrite(pinBuzzer, LOW);
  digitalWrite(Shock, LOW);
}