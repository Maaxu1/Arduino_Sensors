#include "globalSlave.h"
#include "proyecto2.h"
#include "proyecto3.h"
#include "proyecto4.h"

#include <Wire.h>
#include <string.h>
#include<Arduino.h>

int valorSensores;
int orden = 0 ;
int valor  = 0;

void setup() {
  Serial.begin(9600);
  
  // Proyectos 2, 3, 4
  proyecto2Setup();
  proyecto3Setup();
  proyecto4Setup();

  // Comunicación I2C
  Wire.begin(8); // Dirección del esclavo
  Wire.onReceive(recibirDatos);
  Wire.onRequest(enviarDato);  
}

void loop() {
  if(orden == 2) valorSensores = proyecto2();
  if(orden == 3) valorSensores = proyecto3();
  if(orden == 4) valorSensores = proyecto4();
  if(orden == 10) {
    proyecto2Reset();
    proyecto3Reset();
    proyecto4Reset();
    orden = 0;
  }
}

void recibirDatos(int bytes) {
  while (Wire.available()) {
    orden = Wire.read();
  }
}

void enviarDato() {
  Wire.write((byte)(valorSensores >> 8));   // Enviar byte alto
  Wire.write((byte)(valorSensores & 0xFF)); // Enviar byte bajo
}


