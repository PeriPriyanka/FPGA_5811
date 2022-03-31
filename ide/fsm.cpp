#include <Arduino.h>

int A=0,B=0,C=0,D=0,W=0,X=0,Y=0,Z=0; 
void setup()
{
pinMode(2,OUTPUT);
pinMode(3,OUTPUT); 
pinMode(4,OUTPUT);
pinMode(5,OUTPUT); 
pinMode(6,INPUT); 
pinMode(7,INPUT); 
pinMode(8,INPUT);
pinMode(9,INPUT);
pinMode(13,OUTPUT);
}
void loop() 
{   
digitalWrite(13,HIGH);

W= digitalRead(6);
X= digitalRead(7);
Y= digitalRead(8);
Z= digitalRead(9);
//A = (!W&&!X&&!Y&&!Z)||(!W&&X&&!Y&&!Z)||(!W&&!X&&Y&&!Z)||(!W&&X&&Y&&!Z)||(!W&&!X&&!Y&&Z);  
//B = (W&&!X&&!Y&&!Z)||(!W&&X&&!Y&&!Z)||(W&&!X&&Y&&!Z)||(!W&&X&&Y&&!Z);  
//C = (W&&X&&!Y&&!Z)||(!W&&!X&&Y&&!Z)||(W&&!X&&Y&&!Z)||(!W&&X&&Y&&!Z);  
//D = (W&&X&&Y&&!Z)||(!W&&!X&&!Y&&Z);
A = !W;  
B = (Z&&!W)||(X&&W)||(Y&&!X&&!W);  
C = (Z&&!W)||(Y&&W)||(Y&&X);  
D = (!W&&!X&&!Y&&!Z)||(W&&Z); 
digitalWrite(2,A); 
digitalWrite(3,B); 
digitalWrite(4,C);
digitalWrite(5,D);
digitalWrite(13,LOW);
delay(1000);
} 
