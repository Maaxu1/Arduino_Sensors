#include "bluetooth.h"
#include "globalSlave.h"

// Comunicación bluetooth
SoftwareSerial BT(10, 11);

char bluetooth() {
  if (BT.available()) {
    //Serial.write(BT.read());
    char valor = BT.read(); 
    return valor;
  }

}

void bluetoothSetup() {
  BT.begin(9600); // Inicializamos el puerto serie BT (Para Modo AT 2)
}