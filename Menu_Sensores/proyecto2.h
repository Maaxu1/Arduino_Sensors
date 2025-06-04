#ifndef PROYECTO2_H
#define PROYECTO2_H

extern long t;
extern long d;

void proyecto2_setup();

// Función para manejar el sensor de proximidad
void proyecto2() {

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
}

// Función para manejar el sensor de shock
void handleShockSensor() {
  int val = digitalRead(Shock); // Leemos el estado del sensor de shock
  Serial.println(val);
  if(val == HIGH) { // cuando el sensor detecta una señal
    digitalWrite(pinLed, LOW);
    digitalWrite(pinBuzzer, LOW);
  } else {
    digitalWrite(pinLed, HIGH);
    digitalWrite(pinBuzzer, HIGH);
  }
}

void loop() {
  //handleProximitySensor();
  handleShockSensor();
  delay(100); // Pausa antes de la siguiente lectura
}

#endif