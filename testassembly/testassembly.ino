#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *Motorone = AFMS.getMotor(1);
Adafruit_DCMotor *Motortwo = AFMS.getMotor(2);

char serialData; 
int serialInt;

void setup() {
  Serial.begin(9600);
  AFMS.begin();

  Motorone -> setSpeed(0);
  Motorone->run(FORWARD);

  Motortwo -> setSpeed(0);
  Motortwo->run(FORWARD);
}
void loop() {
  if(Serial.available() > 0) {
      serialData = Serial.read();
      serialInt = serialData;
      Serial.println(serialData);
      Serial.print(serialInt);
    
      if(serialInt == 0) {
        
        Motortwo -> setSpeed(180);
        Motortwo->run(FORWARD);
        delay(30);
        Motortwo -> run(BACKWARD);
        delay(38);
        Motortwo -> setSpeed(0);
        }
        
      else if(serialInt == 1) {
        
        Motorone -> setSpeed(180);
        Motorone->run(FORWARD);
        delay(30);
        Motorone -> run(BACKWARD);
        delay(38);
        Motorone -> setSpeed(0);
      }
        
      else if(serialInt == 10) {
        Motorone -> setSpeed(0);
        Motorone->run(FORWARD);
        Motortwo -> setSpeed(0);
        Motortwo->run(FORWARD);
        }
      else if(serialInt == 11) {
        Motorone -> setSpeed(40);
        Motorone->run(FORWARD);
        Motortwo -> setSpeed(40);
        Motortwo->run(FORWARD);
      }
  }
      
  }
  
  
