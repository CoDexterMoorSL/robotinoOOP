#include "robot.h"


int mode       =  3;
int LED_R      = 52;
int LED_Y      = 53;
int modeSwitch = 22;

robot Dakota;

void setup() 
{
  Serial.begin(9600);
  //Mode-LED//
  pinMode(LED_R, OUTPUT);
  pinMode(LED_Y, OUTPUT);
  //Mode-Change//
  pinMode(modeSwitch, INPUT);
}

void loop() 
{
  //------------------
  //mode 0 - Manual Drive       - YR-Const
  //mode 1 - Line Following     -  Y-const
  //mode 2 - Wall Following     -  R-const
  //mode 3 - Obstacle Avoiding  -  R-blink

  //------------------
  //mode change
  if (digitalRead(modeSwitch)==HIGH)
  {
    if (mode == 3){mode = 0;}
    else if (mode == 0 || mode == 1 || mode == 2) {mode+=1;}
    delay(2000);
  }
  //------------------

  if (mode == 0)  // manual
  {
    digitalWrite(LED_R, HIGH); 
    digitalWrite(LED_Y, HIGH);
    Dakota.runManual(); 
  } 
  else if (mode == 1)  // line following
  {
    digitalWrite(LED_R, LOW); 
    digitalWrite(LED_Y, HIGH); 
    Dakota.runLine();
  } 
  else if (mode == 2)  // wall following
  {
    digitalWrite(LED_R, HIGH); 
    digitalWrite(LED_Y, LOW); 
    Dakota.runWall();

  } 
  else if (mode == 3)  // obstacle avoid
  {
    digitalWrite(LED_Y, HIGH); 
    digitalWrite(LED_R, LOW);
    
    Dakota.runObj();
    
    digitalWrite(LED_Y, LOW);
    digitalWrite(LED_R, HIGH);
    delay(50);

  }

  //------------------
}
