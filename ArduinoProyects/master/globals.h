#ifndef GLOBALS_H
#define GLOBALS_H

#include <Wire.h>
#include <Servo.h>
#include <DHT.h>
#include <LiquidCrystal_I2C.h>

extern LiquidCrystal_I2C lcd;

// Pines del joystick
extern const int yAxisPin;
extern const int buttonPin;

// Declaraciones del proyecto 1
extern const int DHpin;
extern const int ledv;
extern const int leda;
extern const int ledr;
extern const int servoPin;

extern bool proyectoActivo;

extern DHT dht;

extern Servo myservo;

// Control de tiempo
extern unsigned long previousMillis;

// Declaraciones del proyecto 2
extern const int Trigger;   
extern const int Echo;      
extern const int pinLed;    
extern const int pinBuzzer; 
extern const int Shock;     

// Declaraciones del proyecto 5
extern const int pinVibracion;
extern const int pinLedV[4];

extern int estadoActualV;
extern int estadoAnteriorV;

// Menú
extern const int numMenuItems;
extern String menuItems[];
extern int menuIndex;
extern bool buttonPressed;
extern bool inMenu;
extern bool sensor1Activo;

#endif