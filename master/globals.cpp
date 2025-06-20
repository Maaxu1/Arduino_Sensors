#include "globals.h"
#define DHTTYPE DHT11 // Sensor DHT11

//Display
//LiquidCrystal_I2C lcd(0x27, 20, 4);

// Pines del joystick
const int yAxisPin = A1;
const int buttonPin = 6;

// Declaraciones del proyecto 1
const int DHpin = 2;
const int ledv = 3;
const int leda = 4;
const int ledr = 5;
const int servoPin = 7;
const int Shock = 11;     // Sensor de choque 
bool proyectoActivo  = false;

DHT dht(DHpin, DHTTYPE); // Declaración del sensor de temperatura

Servo myservo;

// Declaraciones del proyecto 2
const int Trigger = 2;   
const int Echo = 3;      
const int pinLed = 4;    
const int pinBuzzer = 5; 

// Declaraciones del proyecto 5
const int pinVibracion = 13;
const int pinLedV[4] = {11, 10, 9, 8};

int estadoActualV;
int estadoAnteriorV = LOW;

// Comunicación bluetooth
SoftwareSerial BT(10, 11);

bool confirmacionBluetooth = false;
int respuestaBluetooth = -1;

// Menú
const int numMenuItems = 5;
String menuItems[numMenuItems] = {
  "1.Sensor temperat.",
  "2.Sensor proximidad",
  "3.Sensor detonacion",
  "4.Sensor llama",
  "5.Sensor vibracion"
};
int menuIndex = 0;
bool buttonPressed = false;
bool inMenu = true;
bool sensor1Activo = false;
