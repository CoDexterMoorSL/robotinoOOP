#include "robot.h"
// #include "blueTooth.cpp"
#include "Arduino.h"

void robot::runManual()
{
  char c = 'C';
  while (Serial.available() > 0)
  {
    c = Serial.read();
    Serial.println(c);
    
    if (c=='F') 
    {
      motor.setD1_L(1); motor.setD2_L(0);
      motor.setD1_R(1); motor.setD2_R(0);
      motor.setPWM_R(170); motor.setPWM_L(170);
    }
    if (c=='B') 
    {
      motor.setD1_L(0); motor.setD2_L(1);
      motor.setD1_R(0); motor.setD2_R(1);
      motor.setPWM_R(180); motor.setPWM_L(180);
    }
    if (c=='L') 
    {
      motor.setD1_L(1); motor.setD2_L(0);
      motor.setD1_R(1); motor.setD2_R(0);
      motor.setPWM_R(200); motor.setPWM_L(90);
    }

    if (c=='R') 
    { 
      motor.setD1_L(1); motor.setD2_L(0);
      motor.setD1_R(1); motor.setD2_R(0);
      motor.setPWM_R(90); motor.setPWM_L(200);
    }
    if (c=='S') 
    { 
      motor.setD1_L(1); motor.setD2_L(1);
      motor.setD1_R(1); motor.setD2_R(1);
      motor.setPWM_R(0); motor.setPWM_L(0);
    }

  }
}

void robot::runLine()
{
  motor.setD1_L(1);
  motor.setD2_L(0);
  motor.setD1_R(1);
  motor.setD2_R(0);
 
  int kp = 4.0;
  int ki = .1;
  int kd = 0;

  error = IR.returnZigma();

  integral += error;
  derivative = error-previousError;
  previousError = error;

  float controlSignal = kp*error + ki*integral + kd*derivative;
  Serial.println(controlSignal);

  int leftMotorSpeed  = 130 - controlSignal;
  int rightMotorSpeed = 130 + controlSignal;

  motor.setPWM_R(rightMotorSpeed);
  motor.setPWM_L(leftMotorSpeed);

}

void robot::runWall()
{
  motor.setD1_L(0);
  motor.setD2_L(0);
  motor.setD1_R(0);
  motor.setD2_R(0);
  
}

void robot::runObj()
{
  US.updateDistance();
  if(US.runAuto(2))
  {
    motor.setD1_L(1);
    motor.setD2_L(0);
    motor.setD1_R(1);
    motor.setD2_R(0);
  }
  else
  {
    motor.setD1_L(0);
    motor.setD2_L(1);
    motor.setD1_R(1);
    motor.setD2_R(0);
  }
  motor.setPWM_L(US.runAuto(0));
  motor.setPWM_R(US.runAuto(1));
}

  