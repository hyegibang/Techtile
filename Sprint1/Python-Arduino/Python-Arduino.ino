#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *Motorone = AFMS.getMotor(1);
Adafruit_DCMotor *Motortwo = AFMS.getMotor(2);

char serialData ; 
int pinRed = 12; 
int pinYellow = 11;
int pinGreen = 10;

int serialInt;

void setup() {
  Serial.begin(9600);
  AFMS.begin();
  
  pinMode(pinRed, OUTPUT);
  pinMode(pinYellow, OUTPUT);
  pinMode(pinGreen,OUTPUT);
 
}
void loop() {
  if(Serial.available() > 0) {
      serialInt = Serial.read();
      switch(serialInt){
        case '0':
         digitalWrite(pinRed,LOW);
         digitalWrite(pinYellow,LOW);
         digitalWrite(pinGreen,LOW);

          Motorone -> setSpeed(0);
          Motorone->run(FORWARD);
          Motortwo -> setSpeed(0);
          Motortwo->run(FORWARD);
         break;
         
        case '1':
         digitalWrite(pinRed,LOW);
         digitalWrite(pinYellow,LOW);
         digitalWrite(pinGreen,HIGH); 

          Motorone -> setSpeed(180);
          Motorone->run(FORWARD);
          delay(30);
          Motorone -> run(BACKWARD);
          delay(38);
          Motorone -> setSpeed(0);
         break;   
         
        case '2':
         digitalWrite(pinRed,LOW);
         digitalWrite(pinYellow,HIGH);
         digitalWrite(pinGreen,LOW); 

          Motortwo -> setSpeed(180);
          Motortwo->run(FORWARD);
          delay(30);
          Motortwo -> run(BACKWARD);
          delay(38);
          Motortwo -> setSpeed(0);
         break;  
          
        case '3':
         digitalWrite(pinRed,LOW);
         digitalWrite(pinYellow,HIGH);
         digitalWrite(pinGreen,HIGH); 

          Motorone -> setSpeed(0);
          Motorone->run(FORWARD);
          Motortwo -> setSpeed(0);
          Motortwo->run(FORWARD);
          
         break;
            
        case '4':
         digitalWrite(pinRed,HIGH);
         digitalWrite(pinYellow,LOW);
         digitalWrite(pinGreen,LOW); 
         
          Motorone -> setSpeed(0);
          Motorone->run(FORWARD);
          Motortwo -> setSpeed(0);
          Motortwo->run(FORWARD);
         break; 
           
        case '5':
         digitalWrite(pinRed,HIGH);
         digitalWrite(pinYellow,LOW);
         digitalWrite(pinGreen,HIGH);

          Motorone -> setSpeed(0);
          Motorone->run(FORWARD);
          Motortwo -> setSpeed(0);
          Motortwo->run(FORWARD);
         break;  
         
        case '6':
         digitalWrite(pinRed,HIGH);
         digitalWrite(pinYellow,HIGH);
         digitalWrite(pinGreen,LOW); 
         break;  
         
         case '7':
           digitalWrite(pinRed,HIGH);
           digitalWrite(pinYellow,HIGH);
           digitalWrite(pinGreen,HIGH); 
           break;            
      }
  }
}
