#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *Motorone = AFMS.getMotor(1);
Adafruit_DCMotor *Motortwo = AFMS.getMotor(2);

char serialData; 
int pin = 13; 
int pint = 12;
int serialInt;

void setup() {
  Serial.begin(9600);
  AFMS.begin();
  pinMode(pin, OUTPUT);
  pinMode(pint, OUTPUT);
  
 
}
void loop() {
//  Motorone ->setSpeed(10);
//  Motorone->run(FORWARD);
  if(Serial.available() > 0){
      serialData = Serial.read();
      serialInt = serialData;
      Serial.println(serialData);
      Serial.print(serialInt);
    
      if(serialInt == 0){
        digitalWrite(pin,LOW);
        digitalWrite(pint,HIGH);
        Motorone -> setSpeed(0);
        Motorone->run(FORWARD);
        }
        
      else if(serialInt == 1){
        digitalWrite(pin,HIGH);
        digitalWrite(pint,LOW);
        Motorone -> setSpeed(40);
        Motorone->run(FORWARD);
        
        }
        
      else if(serialInt == 10){
        digitalWrite(pin,HIGH);
        digitalWrite(pint,LOW);
        Motorone -> setSpeed(40);
        Motorone->run(FORWARD);
        }
       else if(serialInt == 11){
        digitalWrite(pin,LOW);
        Motorone -> setSpeed(0);
        Motorone->run(FORWARD);
       }
  }
      
  }
  
  
