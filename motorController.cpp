#include "motorController.h"
#include "Arduino.h"

//-----------------------------------------
void motorController::setPWM_L(int value)
{
  PWM_Left_val = value;
  analogWrite(PWM_Left_pin, PWM_Left_val);
}

void motorController::setPWM_R(int value)
{
  PWM_Right_val = value;
  analogWrite(PWM_Right_pin, PWM_Right_val);
}

//-----------------------------------------
void motorController::setD1_L(int value)
{
  D1_Left_val = value;
  if (value == 1){digitalWrite(D1_Left_pin, HIGH);}
  if (value == 0){digitalWrite(D1_Left_pin, LOW);}
}

void motorController::setD2_L(int value)
{
  D2_Left_val = value;
  if (value == 1){digitalWrite(D2_Left_pin, HIGH);}
  if (value == 0){digitalWrite(D2_Left_pin, LOW);}

}
//----------------------------------------

void motorController::setD1_R(int value)
{
  D1_Right_val = value;
  if (value == 1){digitalWrite(D1_Right_pin, HIGH);}
  if (value == 0){digitalWrite(D1_Right_pin, LOW);}
}

void motorController::setD2_R(int value)
{
  D2_Right_val = value;
  if (value == 1){digitalWrite(D2_Right_pin, HIGH);}
  if (value == 0){digitalWrite(D2_Right_pin, LOW);}
}
//----------------------------------------

int motorController::readPWM_L()
{
  return PWM_Left_val;
}

int motorController::readPWM_R()
{
  return PWM_Right_val;
}
