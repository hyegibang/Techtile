#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include <Adafruit_MS_PWMServoDriver.h>
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *Motorone = AFMS.getMotor(1);
Adafruit_DCMotor *Motortwo = AFMS.getMotor(2);

char serialData ; 
int pinRed = 12; // motor
int pinYellow = 5; // solenoid
int pinBlue = 11; // paper 
int sol = 7; 

int serialInt;

void setup() {
  Serial.begin(9600);
  AFMS.begin();
  
  pinMode(pinRed, OUTPUT);
  pinMode(pinYellow, OUTPUT);
  pinMode(pinBlue,OUTPUT);
  pinMode(sol,OUTPUT);
 
}
void loop() {
  if(Serial.available() > 0) {
      serialInt = Serial.read();
      switch(serialInt){
        case '0': // 0 0 
          moveSol();
          moveSol();
          break;
         
        case '1': // 1 0 
          Punch(); 
          moveSol(); 
          noPunch(); 
          moveSol(); 
          break;
         
        case '2': // 0 1 
          noPunch(); 
          moveSol(); 
          Punch(); 
          moveSol(); 
          break;
          
        case '3': // 1 1 
          Punch(); 
          moveSol(); 
          Punch(); 
          moveSol(); 
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
  delay(500);
}

void noPunch(){
  digitalWrite(sol,LOW);  
  digitalWrite(pinRed,LOW);
  delay(500);
}

void Punch(){
  digitalWrite(sol,HIGH);
  digitalWrite(pinRed,HIGH);

  delay(100);
  digitalWrite(sol,LOW); 
  digitalWrite(pinRed,LOW);

  delay(500);
}

void moveSol(){
  digitalWrite(pinYellow,HIGH); 
  delay(100);
  digitalWrite(pinYellow,LOW); 
  delay(100);
}
