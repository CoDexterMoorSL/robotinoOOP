#ifndef usArray_H
#define usArray_H

class usArray 
{
  private:
    int const US_L_Trig = 36;
    int const US_L_Echo = 37;
    int const US_M_Trig = 32;
    int const US_M_Echo = 33;
    int const US_R_Trig = 28;
    int const US_R_Echo = 29;

    int objSafety = 30;
    int runSpeed = 130;

    int usPinArray[3][2] = {{US_L_Trig, US_L_Echo}, {US_M_Trig, US_M_Echo}, {US_R_Trig, US_R_Echo}};
    int distanceArray[3] = {0, 0, 0};

  public:
    int readDistance(int index);
    void updateDistance();
    int calculateDistance(int trigPin, int echoPin);
    int runAuto(int x);
  
};

#endif