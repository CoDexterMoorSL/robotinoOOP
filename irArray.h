#ifndef irArray_H
#define irArray_H

class irArray 
{
  private:
    int const IR1_pin = 50;
    int const IR2_pin = 48;
    int const IR3_pin = 46;
    int const IR4_pin = 44;
    int const IR5_pin = 42;

    int irPinArray[5] = {IR1_pin, IR2_pin, IR3_pin, IR4_pin, IR5_pin};
    int irValArray[5] = {0, 0, 0, 0, 0};
    int irWeightArray[5] = {-3.5,-2,0,2,3.5};

  
  
  public:
    float returnZigma();

};

#endif