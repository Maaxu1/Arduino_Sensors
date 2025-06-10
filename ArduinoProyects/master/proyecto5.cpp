#include "proyecto5.h"
#include "globals.h"

void proyecto5Setup() {
  pinMode(pinVibracion, INPUT);
  
  for(int i = 0; i < 4; i++) {
    pinMode(pinLedV[i], OUTPUT);
  }
}

void proyecto5() {
    estadoActualV = digitalRead(pinVibracion);

  // Detectar flanco ascendente: cuando pasa de LOW a HIGH
  if (estadoActualV == HIGH && estadoAnteriorV == LOW) {
    lcd.setCursor(0, 1);
    lcd.print("Vibracion detectada");

    for (int i = 0; i < 4; i++) {
      digitalWrite(pinLedV[i], HIGH);
      delay(200);
      digitalWrite(pinLedV[i], LOW);
    }

    lcd.setCursor(0, 1);
    lcd.print("                     ");
  }

  // Guardar estado actual como anterior para la próxima vuelta
  estadoAnteriorV = estadoActualV;

  delay(50); // Menor retardo para mayor sensibilidad
}

void proyecto5Reset() {
  estadoActualV = LOW;
  estadoAnteriorV = LOW;
}