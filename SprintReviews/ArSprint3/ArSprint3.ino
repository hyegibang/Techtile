#include <Wire.h>
#include <SpeedyStepper.h>

//
// pin assignments
//
const int MOTOR_X_STEP_PIN = 2; //Gantry
const int MOTOR_Y_STEP_PIN = 3; //Roller
const int MOTOR_X_DIR_PIN = 5;
const int MOTOR_Y_DIR_PIN = 6;
const int STEPPERS_ENABLE_PIN = 8;
int SOLENOID_PIN = 11;
int numcell = 11;
//int onelinesteps = - numcell*(50+50+70); //number of steps for gantry to print one line
int onelinesteps = 850; //number of steps for gantry to print one line
//
// create the stepper motor objects
//
SpeedyStepper stepperX;
SpeedyStepper stepperY;

//char serialInt;
int papermovement = -100;
int solmovement = -100;
int counter_firstdig = 1;
int counter_secdig = 0;

//
char serialInt = '7';
//int serialIntA[25] ;
int serialIntA[8][25] = { 
{0,8,2,8,9,0,8,6,8,9,3,8,1,8,9,2,8,0,8,9,5,8,5,8,9},
{0,8,7,8,9,0,8,1,8,9,3,8,1,8,9,2,8,0,8,9,7,8,7,8,9},
{1,8,5,8,9,0,8,6,8,9,0,8,1,8,9,3,8,1,8,9,2,8,0,8,9},
{1,8,5,8,9,0,8,6,8,9,0,8,1,8,9,3,8,1,8,9,2,8,0,8,9},
{0,8,4,8,9,0,8,6,8,9,3,8,1,8,9,2,8,0,8,9,7,8,5,8,9},
{0,8,2,8,9,0,8,6,8,9,3,8,1,8,9,2,8,0,8,9,5,8,5,8,9},
{0,8,6,8,9,0,8,6,8,9,3,8,1,8,9,2,8,0,8,9,1,8,4,8,9},
{0,8,2,8,9,0,8,6,8,9,3,8,1,8,9,2,8,0,8,9,5,8,5,8,9}
};
int rownumber; 
char select; 

void setup() {
  pinMode(STEPPERS_ENABLE_PIN, OUTPUT);       // be sure to do this
  pinMode(SOLENOID_PIN, OUTPUT);
  pinMode(7, OUTPUT);
  digitalWrite(7, HIGH);
  Serial.begin(9600);



  //
  // connect and configure the stepper motor to there IO pins
  //
  stepperX.connectToPins(MOTOR_X_STEP_PIN, MOTOR_X_DIR_PIN);
  stepperY.connectToPins(MOTOR_Y_STEP_PIN, MOTOR_Y_DIR_PIN);


  //
  // enable the stepper motors
  //
  digitalWrite(STEPPERS_ENABLE_PIN, HIGH);     // be sure to do this
}

void loop() {
  if (Serial.available()) {
    select = Serial.read(); 
    switch(select){
      case 0: // Adams 
       rownumber = 0;
      case 1: // Dancing
       rownumber = 1;
      case 2: // Rocky
       rownumber = 2;
      case 3: // Snowman
       rownumber = 3;
      case 4: // Summer_love
       rownumber = 4;
      case 5: // happy_birthday
       rownumber = 5;
      case 6:  // mary lamb
       rownumber = 6;
      case 7: // silent night
       rownumber = 7;
      case 8: // twinkle twinkle 
       rownumber = 8;
    }
  }
  
  for (int i = 0; i < 25; i++) {
    Serial.print("select"); Serial.println(select);
    Serial.println(serialIntA[rownumber][i]);
    switch (serialIntA[rownumber][i]) {
      case 0: // 0 0 0
        Punch();
        movePaper(papermovement);
        Punch();
        movePaper(papermovement);
        Punch();
        break;

      case 1: // 1 0 0
        Punch();
        movePaper(papermovement);
        noPunch();
        movePaper(papermovement);
        noPunch();
        break;

      case 2: // 0 1 0
        noPunch();
        movePaper(papermovement);
        Punch();
        movePaper(papermovement);
        noPunch();
        break;

      case 3: // 1 1 0
        Punch();
        movePaper(papermovement);
        Punch();
        movePaper(papermovement);
        noPunch();
        break;

      case 4: // 0 0 1
        noPunch();
        movePaper(papermovement);
        noPunch();
        movePaper(papermovement);
        Punch();
        break;

      case 5: // 1 0 1
        Punch();
        movePaper(papermovement);
        noPunch();
        movePaper(papermovement);
        Punch();
        break;

      case 6: // 0 1 1
        noPunch();
        movePaper(papermovement);
        Punch();
        movePaper(papermovement);
        Punch();
        break;

      case 7: // 1 1 1
        Punch();
        movePaper(papermovement);
        Punch();
        movePaper(papermovement);
        Punch();
        break;

      case 8: // new column, paper movement go up
        MoveGantryStepper(800, 800, -50);
        delay(100);
        papermovement = 100;
        break;

      case 9: // new braille, paper movement go down
        MoveGantryStepper(800, 800, -70);
        delay(100);
        papermovement = -100;
        break;

    }
    if (counter_firstdig == 9){
      counter_firstdig = 0;
      counter_secdig += 1;
      }
    else{
      counter_firstdig +=1;
      }
    Serial.print("counter second:"); Serial.println(counter_secdig);
    Serial.print("counter first:"); Serial.println(counter_firstdig);
    if (counter_secdig == 5 && counter_firstdig == 5) {
      newLine();
      Serial.println("newline");
      counter_secdig = 0;
      counter_firstdig = 0;
    }
  }

}

void newLine() {
  MovePaperStepper(200, 200, -400);
  delay(100);
  MoveGantryStepper(800, 800, 1870);
  delay(200);
}

void movePaper(int papermovement) {
  MovePaperStepper(200, 200, papermovement);
  delay(100);
  MovePaperStepper(0, 0, 0);
  delay(500);
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

void moveSol(int solmovemnet) {
  MoveGantryStepper(800, 800, solmovement);
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
