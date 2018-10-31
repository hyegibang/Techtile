#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *Motorone = AFMS.getMotor(1);
Adafruit_DCMotor *Motortwo = AFMS.getMotor(2);

char serialData ; 
int pinRed = 12; // motor
int pinYellow = 11;
int pinGreen = 10; // paper

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
        case '0': // 0 0 0 
          moveSol();
          break;
         
        case '1': // 1 0 0 
          Punch(); 
          movePaper(); 
          noPunch(); 
          movePaper(); 
          noPunch(); 
          movePaper(); 
          break;
         
        case '2':
          noPunch(); 
          movePaper(); 
          Punch(); 
          movePaper(); 
          noPunch(); 
          movePaper(); 
          break;
          
        case '3':
          Punch(); 
          movePaper(); 
          Punch(); 
          movePaper(); 
          noPunch(); 
          movePaper(); 
          break;
            
        case '4':
          noPunch(); 
          movePaper(); 
          noPunch(); 
          movePaper(); 
          Punch(); 
          movePaper(); 
           
        case '5':
          Punch(); 
          movePaper(); 
          noPunch(); 
          movePaper(); 
          Punch(); 
          movePaper(); 
          break;
         
        case '6':
          noPunch(); 
          movePaper(); 
          Punch(); 
          movePaper(); 
          Punch(); 
          movePaper(); 
          break;  
         
         case '7':
          Punch(); 
          movePaper(); 
          Punch(); 
          movePaper(); 
          Punch(); 
          movePaper(); 
          break;

        case '8':
          moveSol();
          moveSol();
          break;
     }
  }
}

void movePaper(){
  digitalWrite(pinGreen,HIGH);
  delay(100);
  digitalWrite(pinGreen,LOW);
  delay(500);
}

void noPunch(){
  digitalWrite(pinRed,LOW);
  delay(500);
}

void Punch(){
  digitalWrite(pinRed,HIGH);
  delay(100);
  digitalWrite(pinRed,LOW); 
  delay(500);
}

void moveSol(){
  digitalWrite(pinYellow,HIGH); 
  delay(100);
  digitalWrite(pinYellow,LOW); 
  delay(100);
}
