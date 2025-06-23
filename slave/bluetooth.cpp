#include "bluetooth.h"

SoftwareSerial BT(10, 11); // RX, TX

void bluetoothSetup() {
  BT.begin(9600);
}

char bluetooth() {
  if (BT.available()) {
    return BT.read();
  }
  return 0;
}
