#include "Arduino.h"
#include "types.h"
      
      /* for base Drive */
// Define Base Motors  
#define enAV 11   
#define enBV 10
#define enA1 9    
#define enA2 8
#define enB1 7    
#define enB2 6
// Define Control Pins for base
#define forwardPin 4
#define backPin 2
#define leftPin 5
#define rightPin 3 

      /* for lifters Drive */
// Define Lifters Motors 
#define M11 22    
#define M12 23
#define M21 24    
#define M22 25

#define M31 26    
#define M32 27
#define M41 28    
#define M42 29 
// Define Limit Switches
#define LSW11 30    
#define LSW12 31 
#define LSW21 32    
#define LSW22 33

#define LSW31 34    
#define LSW32 35
#define LSW41 36    
#define LSW42 37
// Define Grippers 
#define Grip1 38
#define Grip2 39
#define Grip3 40
#define Grip4 41
// Define Operations start pins
#define OP1 42
#define OP2 43
#define OP3 44
#define OP4 45
//Define Gripers Release Operations 
#define Re1 46
#define Re2 47
#define Re3 48
#define Re4 49



/* Functions for Base Drive */ 
void forward(){
  analogWrite(enAV,255);
  analogWrite(enBV,255);
  digitalWrite(enA1,HIGH);digitalWrite(enA2,LOW);
  digitalWrite(enB1,HIGH);digitalWrite(enB2,LOW);}
void backward(){
  analogWrite(enAV,255);
  analogWrite(enBV,255);
  digitalWrite(enA1,LOW);digitalWrite(enA2,HIGH);
  digitalWrite(enB1,LOW);digitalWrite(enB2,HIGH);}
void left(){
  analogWrite(enAV,128);
  analogWrite(enBV,80);
  digitalWrite(enA1,HIGH);digitalWrite(enA2,LOW);
  digitalWrite(enB1,LOW);digitalWrite(enB2,HIGH);}
void right(){
  analogWrite(enAV,80);
  analogWrite(enBV,128);
  digitalWrite(enA1,LOW);digitalWrite(enA2,HIGH);
  digitalWrite(enB1,HIGH);digitalWrite(enB2,LOW);}
void Stop(){
  analogWrite(enAV,0);
  analogWrite(enBV,0);
  digitalWrite(enA1,LOW);digitalWrite(enA2,LOW);
  digitalWrite(enB1,LOW);digitalWrite(enB2,LOW);}

/* Functions for Operations */ 

static inline uint_16 End(uint_8 Mpos,uint_8 Mneg){
  digitalWrite(Mpos,LOW);digitalWrite(Mneg,LOW);}

uint_16 UP(uint_8 Mpos,uint_8 Mneg,uint_8 LSW) {
  uint_8 value=digitalRead(LSW);
  while(value==LOW){
    digitalWrite(Mpos,HIGH);digitalWrite(Mneg,LOW);
    value=digitalRead(LSW);}
    if(value==HIGH){End(Mpos,Mneg);}}

uint_16 Down(uint_8 Mpos,uint_8 Mneg,uint_8 LSW){
  uint_8 value=digitalRead(LSW);
  while(value==LOW){
    digitalWrite(Mpos,LOW);digitalWrite(Mneg,HIGH);
    value=digitalRead(LSW);}
    if(value==HIGH){End(Mpos,Mneg);}}

/* For Griper On\Off */
#define Gripper(GripPin,Case){digitalWrite(GripPin,Case);}
  
