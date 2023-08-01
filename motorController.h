#ifndef motorController_H
#define motorController_H

class motorController
{
  public:
    
    //----Pin Numbers----------//

    int const D1_Left_pin   = 4;
    int const D2_Left_pin   = 5;

    int const D1_Right_pin  = 6;
    int const D2_Right_pin  = 7;
    
    int const PWM_Left_pin  = 8;
    int const PWM_Right_pin = 9;

    //-------------------------//

    int PWM_Right_val = 0;
    int PWM_Left_val  = 0;

    int D1_Left_val = 0;
    int D2_Left_val = 0;
    
    int D1_Right_val = 0;
    int D2_Right_val = 0;


    void setPWM_L(int value);
    void setPWM_R(int value);
    
    void setD1_L(int value);
    void setD2_L(int value);
    
    void setD1_R(int value);
    void setD2_R(int value);
    
    int readPWM_L();
    int readPWM_R();
};


#endif