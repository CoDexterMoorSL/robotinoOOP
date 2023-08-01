#ifndef robot_H
#define robot_H

#include "motorController.h"
#include "irArray.h"
#include "usArray.h"

class robot
{
  private:
    motorController motor;
    irArray IR;
    usArray US;
    
    float error = 0;
    float integral =  0;
    float derivative = 0;
    float previousError = 0;

  public:
    void runManual();
    void runLine();
    void runWall();
    void runObj();

};


#endif