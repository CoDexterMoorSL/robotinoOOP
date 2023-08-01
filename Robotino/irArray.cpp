#include "irArray.h"
#include "Arduino.h"

float irArray::returnZigma()
{
  float zigma = 0;;
  
  for (int i = 0 ; i < 5 ; i++)
  {
    irValArray[i] = !(digitalRead(irPinArray[i]));
    zigma += irWeightArray[i] * irValArray[i];
  }
  if (zigma/abs(zigma) > 0 && irValArray[2]==1) { zigma +=3;}
  if (zigma/abs(zigma) < 0 && irValArray[2]==1) { zigma -=3;}
  return zigma* 3 ; 
}
