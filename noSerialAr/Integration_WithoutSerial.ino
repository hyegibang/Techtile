#include <Wire.h>
#include <SpeedyStepper.h>


 // pin assignments

const int MOTOR_X_STEP_PIN = 2; //Gantry
const int MOTOR_Y_STEP_PIN = 3; //Roller
const int MOTOR_X_DIR_PIN = 5;
const int MOTOR_Y_DIR_PIN = 6;
const int STEPPERS_ENABLE_PIN = 8;
int SOLENOID_PIN = 11;

//
// create the stepper motor objects
//
SpeedyStepper stepperX;
SpeedyStepper stepperY;

char serialInt; 
int papermovement = 800; 
int solmovement; 

void setup() {
  pinMode(STEPPERS_ENABLE_PIN, OUTPUT);       // be sure to do this
  pinMode(SOLENOID_PIN, OUTPUT);
  Serial.begin(9600);

  //connect and configure the stepper motor to there IO pins
  
  stepperX.connectToPins(MOTOR_X_STEP_PIN, MOTOR_X_DIR_PIN);
  stepperY.connectToPins(MOTOR_Y_STEP_PIN, MOTOR_Y_DIR_PIN);

//   enable the stepper motors
  
  digitalWrite(STEPPERS_ENABLE_PIN, HIGH);     // be sure to do this
}
void loop() {
  if(Serial.available() > 0) {
      serialInt = Serial.read();
      switch (serialInt) {
        case '0': // 0 0 0 
          Punch();
          movePaper(papermovement);
          Punch();
          movePaper(papermovement);
          Punch(); 
          break;
    
        case '1': // 1 0 0
          Punch();
          movePaper(papermovement);
          noPunch();
          movePaper(papermovement);
          noPunch();
          break;
    
        case '2': // 0 1 0 
          noPunch();
          movePaper(papermovement);
          Punch();
          movePaper(papermovement);
          noPunch();
          break;
    
        case '3': // 1 1 0
          Punch();
          movePaper(papermovement);
          Punch();
          movePaper(papermovement);
          noPunch(); 
          break;
    
        case '4': // 0 0 1
          noPunch();
          movePaper(papermovement);
          noPunch();
          movePaper(papermovement);
          Punch();
          break;
    
        case '5': // 1 0 1
          Punch();
          movePaper(papermovement);
          noPunch();
          movePaper(papermovement);
          Punch();
          break;
    
        case '6': // 0 1 1
          noPunch();
          movePaper(papermovement);
          Punch();
          movePaper(papermovement);
          Punch();
          break;
    
        case '7': // 1 1 1
          Punch();
          movePaper(papermovement);
          Punch();
          movePaper(papermovement);
          Punch();
          break;
    
        case '8': // new column, paper movement go up
          moveSol(-35); // column distance, negative go right 
          papermovement = -100;
          break;
  
        case '9': // new braille, paper movement go down  
          moveSol(-60); // braille distance
          papermovement = 100;
          break; 
        
    }
  }
}

void movePaper(int papermovement) {
  MovePaperStepper(200,200,papermovement);
  delay(100);
}

void noPunch() {
  digitalWrite(SOLENOID_PIN, LOW);
  delay(500);
}

void Punch() {
  digitalWrite(SOLENOID_PIN, HIGH);
  delay(100);
  digitalWrite(SOLENOID_PIN, LOW);
  delay(500);
}

void moveSol(int solmovement) {
  MoveGantryStepper(800, 800, solmovement);
  delay(100);
  MoveGantryStepper(800, 800, 0);
  delay(100);
}

void MoveGantryStepper(int Vel, int Accel, int NumSteps)
/*
   Velocity and acceleration are set to be same values
   1600 steps is one full rotation
*/
{
  //
  // set the speed and acceleration rates for the stepper motor
  //
  stepperX.setSpeedInStepsPerSecond(Vel);
  stepperX.setAccelerationInStepsPerSecondPerSecond(Accel);
  stepperX.moveRelativeInSteps(NumSteps);

  //
  // now that the rotation has finished, delay 1 second before starting
  // the next move
  //
  delay(1000);
}

void MovePaperStepper(int Vel, int Accel, int NumSteps)
/*
   Velocity and acceleration are set to be same values
   1600 steps is one full rotation
*/
{
  //
  // set the speed and acceleration rates for the stepper motor
  //
  stepperY.setSpeedInStepsPerSecond(Vel);
  stepperY.setAccelerationInStepsPerSecondPerSecond(Accel);
  stepperY.moveRelativeInSteps(NumSteps);

  //
  // now that the rotation has finished, delay 1 second before starting
  // the next move
  //
  delay(1000);
}
