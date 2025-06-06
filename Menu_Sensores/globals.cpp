#include "globals.h"
#define DHTTYPE DHT11 // Sensor DHT11

//Display
LiquidCrystal_I2C lcd(0x27, 20, 4);

// Pines del joystick
const int yAxisPin = A1;
const int buttonPin = 6;

// Declaraciones del proyecto 1
const int DHpin = 2;
const int ledv = 3;
const int leda = 4;
const int ledr = 5;
const int servoPin = 7;
const int Shock = 11;     //sensor de choque 
bool proyectoActivo  = false;

DHT dht(DHpin, DHTTYPE);

Servo myservo;

// Declaraciones del proyecto 2
const int Trigger = 2;   
const int Echo = 3;      
const int pinLed = 4;    
const int pinBuzzer = 5; 
const int Shock = 11;    


// Declaraciones del proyecto 3


// Declaraciones del proyecto 4

// Declaraciones del proyecto 5
const int pinVibracion = 13;
const int pinLedV[4] = {11, 10, 9, 8};

int estadoActualV;
int estadoAnteriorV = LOW;

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