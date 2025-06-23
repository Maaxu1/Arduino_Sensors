#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include <SoftwareSerial.h>

extern SoftwareSerial BT;

char bluetooth();
void bluetoothSetup();

#endif