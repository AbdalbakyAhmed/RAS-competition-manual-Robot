#include "Arduino.h"

#define uint_8 unsigned char
#define uint_16 unsigned int
#define uint_32 unsigned long 
#define Catch HIGH
#define Release LOW 

#define SetupOutput(x,y) for(uint_8 i=x;i<=y;i++){pinMode (i,OUTPUT);} //to setup OUTPUT PINS 
#define SetupInput(x,y) for(uint_8 i=x;i<=y;i++){pinMode (i,INPUT);}   //to setup INPUT PINS 
