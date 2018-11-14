#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_StepperMotor *stepper = AFMS.getStepper(200, 2);


char serialData ; 
int pinRed = 12; // motor
int pinGreen = 5; // solenoid
int pinBlue = 11; // paper
int sol = 7; 

int serialInt = 5;

void setup() {
  Serial.begin(9600);
  AFMS.begin();
  
  pinMode(pinRed, OUTPUT);
  pinMode(pinGreen, OUTPUT);
  pinMode(pinBlue,OUTPUT);

  pinMode(sol,OUTPUT);
  stepper -> setSpeed(10); // 10 rpm 
 
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
         
        case '2': // 0 1 0 
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
  digitalWrite(pinBlue,HIGH);
  delay(100);
  digitalWrite(pinBlue,LOW);
  delay(200);
}

void noPunch(){
  digitalWrite(pinRed,LOW);
  digitalWrite(sol,LOW);

  delay(200);
}

void Punch(){
  digitalWrite(pinRed,HIGH);
  digitalWrite(sol,HIGH);
  delay(100);
  digitalWrite(pinRed,LOW); 
  digitalWrite(sol,LOW);
  delay(200);

}

void moveSol(){
  stepper->step(4, FORWARD, SINGLE); 
  delay(500);
}

void movecolumnSol(){
  stepper->step(7, FORWARD, SINGLE); 
  delay(500);
}
  
}
