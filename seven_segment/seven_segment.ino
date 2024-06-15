#include "TM1637.h"
#define CLK 3//pins definitions for TM1637 and can be changed to other 

#define DIO 4
TM1637 tm1637(CLK,DIO);
void setup()
{
tm1637.init();
tm1637.set(BRIGHT_TYPICAL);//BRIGHT_TYPICAL = 2,BRIGHT_DARKEST = 0,BRIGHTEST = 7;

}
void loop()
{
int8_t ListDisp[4]={1,2,3,4};
 tm1637.display(0,ListDisp[0]);
 tm1637.display(1,ListDisp[1]);
 tm1637.display(2,ListDisp[2]);
 tm1637.display(3,ListDisp[3]);
 delay(300);
}
