#include "globals.h"
#include "proyecto1.h"
#include "proyecto2.h"
#include "proyecto5.h"

bool transmision_iniciada;

void setup() {
  lcd.init();
  lcd.backlight();
  
  pinMode(buttonPin, INPUT_PULLUP);
  showMenu();

  proyecto1_setup();
  proyecto2_setup();
  proyecto5_setup();

  Wire.begin(); // Inicia como maestro

  Serial.begin(9600);
}

void loop() {
  int yValue = analogRead(yAxisPin);
  bool currentButton = digitalRead(buttonPin) == LOW;

  if (inMenu) {
    proyecto1_reset();
    proyecto2_reset();
    proyecto5_reset();

    // Navegación con el joystick
    if (yValue < 400) {
      menuIndex = (menuIndex - 1 + numMenuItems) % numMenuItems;
      showMenu();
      delay(250);
    } else if (yValue > 600) {
      menuIndex = (menuIndex + 1) % numMenuItems;
      showMenu();
      delay(250);
    }

    // Selección
    if (currentButton && !buttonPressed) {
      buttonPressed = true;
      inMenu = false;
      switch (menuIndex) {
        case 0: sensor1(); break;
        case 1: sensor2(); break;
        case 2: sensor3(); break;
        case 3: sensor4(); break;
        case 4: sensor5(); break;
      }
    }
} else {
  if (!proyectoActivo ) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Iniciando proyecto ");
    lcd.print(menuIndex + 1); // Para que muestre del 1 al 5
    lcd.setCursor(0, 3);
    lcd.print("Presiona para volver");
    proyectoActivo  = true;
  }

  switch (menuIndex) {
    case 0: sensor1(); break;
    case 1: sensor2(); break;
    case 2: sensor3(); break;
    case 3: sensor4(); break;
    case 4: sensor5(); break;
  }

  // Esperar pulsación para regresar al menú
  if (currentButton && !buttonPressed) {
    buttonPressed = true;
    inMenu = true;
    proyectoActivo  = false; // Reiniciar bandera al volver

    Wire.beginTransmission(8);
    Wire.write(10); // Comando para detener
    Wire.endTransmission();

    transmision_iniciada = false;

    showMenu();
  }
}

  if (!currentButton) {
    buttonPressed = false;
  }
}

void showMenu() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Menu:");
  for (int i = 0; i < 3; i++) {
    int itemIndex = (menuIndex + i) % numMenuItems;
    lcd.setCursor(0, i + 1);
    lcd.print((i == 0) ? ">" : " ");
    lcd.print(menuItems[itemIndex]);
  }
}

// Funciones para cada opción del menú
void sensor1() {
  proyecto1();
}

void sensor2() {
  if (transmision_iniciada == false) {
    Wire.beginTransmission(8);
    Wire.write(2); // Comando para Proyecto 3
    Wire.endTransmission();
    transmision_iniciada = true;
    

    Serial.print("Distancia: ");

  } else {
    Wire.requestFrom(8, 10); // Pide 1 byte al esclavo 8

    if (Wire.available()) {
      byte data = Wire.read(); // Lee el byte

      Serial.print(data);
      Serial.println(" cm");

      delay(1000);

      Serial.print("         ");
    }
  }
}

void sensor3() {
  if (transmision_iniciada == false) {
    Wire.beginTransmission(8);
    Wire.write(3); // Comando para Proyecto 3
    Wire.endTransmission();
    transmision_iniciada = true;
  } else {
    Wire.requestFrom(8, 10); // Pide 1 byte al esclavo 8

    if (Wire.available()) {
      byte data = Wire.read(); // Lee el byte

      lcd.setCursor(0, 1);
      lcd.print("Golpe detectado");

      lcd.setCursor(0, 1);
      lcd.print("                  ");
    }
  }
}

void sensor4() {
    if (transmision_iniciada == false) {
    Wire.beginTransmission(8);
    Wire.write(4); // Comando para Proyecto 4
    Wire.endTransmission();
    transmision_iniciada = true;
  } else {
    Wire.requestFrom(8, 10); // Pide 1 byte al esclavo 8

    if (Wire.available()) {
      byte data = Wire.read(); // Lee el byte

      lcd.setCursor(0, 1);
      lcd.print("Golpe detectado");

      lcd.setCursor(0, 1);
      lcd.print("                     ");
    }
  }
}
void sensor5() {
  proyecto5();
}