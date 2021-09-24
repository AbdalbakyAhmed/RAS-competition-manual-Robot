#include "HW_interface.h"

uint_8 valueF,valueB,valueR,valueL;
uint_8 op1sw,op2sw,op3sw,op4sw;
void setup(){
  SetupOutput(6,11);SetupInput(3,5);
  SetupOutput(22,29);SetupInput(30,37);SetupInput(42,49);
  SetupOutput(38,39);
}
void loop(){
  /* For base Directions Drive */
  valueF=0,valueB=0,valueL=0,valueR=0;
  valueF=digitalRead(forwardPin);
  valueB=digitalRead(backPin);
  valueL=digitalRead(leftPin);
  valueR=digitalRead(rightPin);
  if(valueF==HIGH&&valueB==LOW&&valueL==LOW&&valueR==LOW){forward();/*while(valueF==HIGH&&valueB==LOW&&valueL==LOW&&valueR==LOW);*/}
  else{Stop();while(valueF==LOW&&valueB==LOW&&valueL==LOW&&valueR==LOW);}
  if(valueF==LOW&&valueB==HIGH&&valueL==LOW&&valueR==LOW){backward();/*while(valueF==LOW&&valueB==HIGH&&valueL==LOW&&valueR==LOW);*/}
  else{Stop();while(valueF==LOW&&valueB==LOW&&valueL==LOW&&valueR==LOW);}
  if(valueF==LOW&&valueB==LOW&&valueL==HIGH&&valueR==LOW){left();/*while(valueF==LOW&&valueB==LOW&&valueL==HIGH&&valueR==LOW);*/}
  else{Stop();while(valueF==LOW&&valueB==LOW&&valueL==LOW&&valueR==LOW);}
  if(valueF==LOW&&valueB==LOW&&valueL==LOW&&valueR==HIGH){right();/*while(valueF==LOW&&valueB==LOW&&valueL==LOW&&valueR==HIGH);*/}
  else{Stop();while(valueF==LOW&&valueB==LOW&&valueL==LOW&&valueR==LOW);}
  if(valueF==LOW&&valueB==LOW&&valueL==LOW&&valueR==LOW){Stop();/*while(valueF==LOW&&valueB==LOW&&valueL==LOW&&valueR==LOW);*/}
  else{Stop();while(valueF==LOW&&valueB==LOW&&valueL==LOW&&valueR==LOW);}

  /* For Operation Start */ 
  op1sw=0,op2sw=0,op3sw=0,op4sw=0;
  op1sw=digitalRead(OP1);
  op2sw=digitalRead(OP2);
  op3sw=digitalRead(OP3);
  op4sw=digitalRead(OP4);
  // Operation 1
  if(op1sw==HIGH){
    Gripper(Grip2,Catch);delay(100);
    UP(M21,M22,LSW21);Gripper(Grip1,Catch);Gripper(Grip2,Release);delay(100);
    Down(M21,M22,LSW22);}
  //Operation 2
  if(op2sw==HIGH){
    UP(M11,M12,LSW11);delay(2000);
  Gripper(Grip2,Catch);}  
  //Operation 3
  if(op3sw==HIGH){
    Gripper(Grip3,Catch);delay(100);
    UP(M31,M32,LSW31);Gripper(Grip4,Catch);Gripper(Grip3,Release);delay(100);
    Down(M31,M32,LSW32);}          
  //Operation 4
  if(op4sw==HIGH){
    UP(M41,M42,LSW41);delay(2000);
    Gripper(Grip3,Catch);}
  // Bulid Operations 
  op1sw=0,op2sw=0,op3sw=0,op4sw=0;
  op1sw==digitalRead(Re1);
  op2sw==digitalRead(Re2);
  op3sw==digitalRead(Re3);
  op4sw==digitalRead(Re4);
  //Gripper 1 Release 
  if (op1sw==HIGH){Gripper(Grip1,Release);}
  //Gripper 2 Release
  if (op2sw==HIGH){Gripper(Grip2,Release);}   
  //Gripper 1 Release
  if (op3sw==HIGH){Gripper(Grip3,Release);}
  //Gripper 1 Release
  if (op4sw==HIGH){Gripper(Grip4,Release);}
}
