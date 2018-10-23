#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *Motorone = AFMS.getMotor(1);
Adafruit_DCMotor *Motortwo = AFMS.getMotor(2);

char serialData ; 
int pin = 13; 
int pint = 12;
int serialInt;

void setup() {
  Serial.begin(9600);
  pinMode(pin, OUTPUT);
  pinMode(pint, OUTPUT);
 
}
void loop() {
  if(Serial.available() > 0){
      serialData = Serial.read();
      serialInt = serialData;

      switch(serialInt){
        case 0:
          digitalWrite(pin,LOW);
          digitalWrite(pint,HIGH);
          Motorone -> setSpeed(0);
          Motortwo -> setSpeed(0);
          delay(200);
          break;
        case 1:
          digitalWrite(pin,HIGH);
          digitalWrite(pint,LOW);
          Motorone -> setSpeed(0);
          Motortwo -> setSpeed(0);
          delay(200);
          break;
        case 10:
          digitalWrite(pin,HIGH);
          digitalWrite(pint,LOW);
          Motorone -> setSpeed(50);
          Motortwo -> setSpeed(0);
          delay(200); 
          break;
        case 11:
          digitalWrite(pin,LOW);
          digitalWrite(pint,HIGH);
          Motorone -> setSpeed(0);
          Motortwo -> setSpeed(0);
          delay(200);
       }
     
      
  }
  }
  
