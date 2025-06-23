#include "globals.h"
#include "proyecto1.h"
#include "proyecto5.h"

LiquidCrystal_I2C lcd(0x27, 20, 4);
bool transmision_iniciada;

void setup() {
  Wire.begin(); // Inicia como maestro
  lcd.init();
  lcd.backlight();
  
  pinMode(buttonPin, INPUT_PULLUP);
  showMenu();

  proyecto1Setup();
  proyecto5Setup();

  Serial.begin(9600);
}

void loop() {
  int yValue = analogRead(yAxisPin);
  bool currentButton = digitalRead(buttonPin) == LOW;

  Wire.requestFrom(8, 2);

  if (Wire.available() >= 2) {
    byte highByte = Wire.read();
    byte lowByte = Wire.read();

    char recibido = (highByte << 8) | lowByte;
    Serial.println(recibido);

    // Selección de proyecto (a-e o A-E)
    if (recibido >= 'a' && recibido <= 'e') {
      respuestaBluetooth = recibido - 'a';
      menuIndex = respuestaBluetooth;
      confirmacionBluetooth = true;
    }
    else if (recibido >= 'A' && recibido <= 'E') {
      respuestaBluetooth = recibido - 'A';
      menuIndex = respuestaBluetooth;
      confirmacionBluetooth = true;
    }

    // Salida de proyecto (r o R)
    else if (recibido == 'r' || recibido == 'R') {
      if (!inMenu) {  // Solo si estás en un proyecto
        confirmacionBluetooth = true; // Activar salida
      }
    }

    Serial.println("Hay comunicacion");
  }

  if (inMenu) {
    delay(50);
    proyecto1Reset();
    proyecto5Reset();

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
    if ((currentButton && !buttonPressed) || confirmacionBluetooth == true) {
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
  if (!proyectoActivo) {
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
  if ((currentButton && !buttonPressed) || confirmacionBluetooth == true) {
    buttonPressed = true;
    inMenu = true;
    proyectoActivo = false; // Reiniciar bandera al volver
    confirmacionBluetooth = false;

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
    Wire.write(2); // Comando para Proyecto 2
    Wire.endTransmission();
    transmision_iniciada = true;

  } else {
    Wire.requestFrom(8, 2); // Pide 2 byte al esclavo 8

    //prueba de comunicacion de int
    if (Wire.available() >= 2) {
      byte highByte = Wire.read();
      byte lowByte = Wire.read();

      int valor = (highByte << 8) | lowByte;
      Serial.println(valor);

      lcd.setCursor(0, 1);
      lcd.print("                  ");  // Limpiar primero
      lcd.setCursor(0, 1);
      lcd.print("Distancia: ");
      lcd.print(valor);
      lcd.print(" CM");

      delay(200);

    } else {
      Serial.println("No hay comunicacion");
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
    Wire.requestFrom(8, 2); // Pide 1 byte al esclavo 8

    if (Wire.available()) {
      byte highByte = Wire.read();
      byte lowByte = Wire.read();
      int valor = (highByte << 8) | lowByte; // Reconstruir int
      Serial.println(valor);
      if (valor == 0 ) {
        lcd.setCursor(0, 1);
        delay(200);
        lcd.setCursor(0, 1);
        lcd.print("                  ");
        lcd.setCursor(0, 1);
        lcd.print("Golpe detectado");
        lcd.setCursor(0, 1);
        lcd.print("                  ");
        lcd.setCursor(0, 1);
        lcd.print("Golpe Detectado");
        delay(100);
      } else {
        lcd.setCursor(0, 1);
        lcd.print("                  ");
        lcd.setCursor(0, 1);
        lcd.print("Golpe no Detectado");
        delay(200);
      }
      delay(100);

    } else {
      Serial.println("No hay comunicacion");
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
    Wire.requestFrom(8, 2); // Pide 1 byte al esclavo 8

    if (Wire.available()) {
      byte highByte = Wire.read();
      byte lowByte = Wire.read();
      int valor = (highByte << 8) | lowByte; // Reconstruir int
      Serial.println(valor);

      if (valor < 500) {
        lcd.setCursor(0, 1);
        lcd.print("LLama Detectada");
        delay(100);
      } else {
        lcd.setCursor(0, 1);
        lcd.print("LLama no Detectada");
        delay(100);
      }
      
      lcd.setCursor(0, 1);
      lcd.print("                     ");
      
    } else {
      Serial.println("No hay comunicacion");
    }
  }
}

void sensor5() {
  proyecto5();
}