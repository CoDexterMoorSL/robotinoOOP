#include "usArray.h"
#include "Arduino.h"

int usArray::readDistance(int index)
{
  return distanceArray[index];
}

void usArray::updateDistance()
{
  for (int i = 0 ; i<3 ; i++)
  {
    distanceArray[i] = calculateDistance(usPinArray[i][0], usPinArray[i][1]);
  }
}

int usArray::calculateDistance(int trigPin, int echoPin)
{
  long duration;
  int cm;
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  cm = duration / 29 / 2;
  return cm;
}

int usArray::runAuto(int x)
{
  int speed[3] = {0,0,1};
  
  if (distanceArray[1]>objSafety)
  {
    if(distanceArray[0]<objSafety)
    {
      speed[0] = runSpeed;
      speed[1] = 0;
      speed[2] = 0;
    }
    else if(distanceArray[2]<objSafety)
    {
      speed[0] = 0;
      speed[1] = runSpeed;
      speed[2] = 0;
    }
    else
    {
      speed[0] = runSpeed;
      speed[1] = runSpeed;
      speed[2] = 1;
    }
  }
  else if(distanceArray[0]<objSafety)
  {
    speed[0] = 0;
    speed[1] = runSpeed;
    speed[2] = 0;
  }
  else if(distanceArray[2]<objSafety)
  {
    speed[0] = runSpeed;
    speed[1] = 0;
    speed[2] = 0;
  }
  else
  {
    speed[0] = runSpeed * 1.5;
    speed[1] = runSpeed * 1.5;
    speed[2] = 1;
  }

  if (distanceArray[0]<objSafety && distanceArray[1]<objSafety && distanceArray[2]<objSafety)
  {
    speed[0] = runSpeed * 2;
    speed[1] = runSpeed * 1.5;
    speed[2] = 0;
  }

  if (x == 0){return speed[0];}
  else if (x==1) {return speed[1];}
  else if (x==2) {return speed[2];}
}