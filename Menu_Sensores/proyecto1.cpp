#include "proyecto1.h"
#include "globals.h"

void proyecto1_setup() {
  // Inicializar DHT
  dht.begin();

  // Inicializar servo
  myservo.attach(servoPin);

  // Inicializar LEDs
  pinMode(ledv, OUTPUT);
  pinMode(leda, OUTPUT);
  pinMode(ledr, OUTPUT);

  // Apagar todos los LEDs al inicio
  digitalWrite(ledv, LOW);
  digitalWrite(leda, LOW);
  digitalWrite(ledr, LOW);
}

void proyecto1() {
  static unsigned long previousMillis = 0;
  const unsigned long intervalo = 2000;
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= intervalo) {
    previousMillis = currentMillis;

    float temperatura = dht.readTemperature();

    if (isnan(temperatura)) {
      Serial.println("Error al leer DHT11");
      digitalWrite(ledv, LOW);
      digitalWrite(leda, LOW);
      digitalWrite(ledr, LOW);
      myservo.write(0);
      return;
    }

    // Lógica de LEDs
    if (temperatura >= 0 && temperatura <= 24) {
      digitalWrite(ledv, HIGH); digitalWrite(leda, LOW); digitalWrite(ledr, LOW);
    } else if (temperatura > 24 && temperatura <= 30) {
      digitalWrite(ledv, LOW); digitalWrite(leda, HIGH); digitalWrite(ledr, LOW);
    } else if (temperatura > 30 && temperatura <= 35) {
      digitalWrite(ledv, LOW); digitalWrite(leda, LOW); digitalWrite(ledr, HIGH);
    } else {
      digitalWrite(ledv, LOW); digitalWrite(leda, LOW); digitalWrite(ledr, LOW);
    }

    // Servo
    int angulo = 0;
    if (temperatura >= 24 && temperatura <= 30) {
      angulo = map(temperatura, 24, 30, 45, 90);
    } else if (temperatura > 30 && temperatura <= 35) {
      angulo = map((int)temperatura, 31, 35, 91, 180);
    } else {
      angulo = 0;
    }
    myservo.write(angulo);

    // LCD
    lcd.setCursor(0, 1);
    lcd.print("Temp: ");
    lcd.print(temperatura);
    lcd.print("   ");

    lcd.setCursor(0, 2);
    lcd.print("Servo: ");
    lcd.print(angulo);
    lcd.print("    ");

    // Serial
    Serial.print("Temp: ");
    Serial.println(temperatura);
    Serial.print("Servo: ");
    Serial.println(angulo);
  }
}

void proyecto1_reset() {
  digitalWrite(ledv, LOW);
  digitalWrite(leda, LOW);
  digitalWrite(ledr, LOW);
}
