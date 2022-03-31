#include <Arduino.h>
int A=0,B=0,C=0,D=0,a,b,c,d,e,f,g,W,X,Y,Z; 
void setup()
{
pinMode(2,OUTPUT);
pinMode(3,OUTPUT); 
pinMode(4,OUTPUT);
pinMode(5,OUTPUT); 
pinMode(6,OUTPUT); 
pinMode(7,OUTPUT); 
pinMode(8,OUTPUT);
}
void loop() 
{   
a=(!D&&!C&&!B&&A)||(!D&&C&&!B&&!A); 
b=(!D&&C&&!B&&A)||(!D&&C&&B&&!A); 
c=(!D&&!C&&B&&!A); 
d=(!D&&!C&&!B&&A)||(!D&&C&&!B&&!A)||(!D&&C&&B&&A); 
e=(!D&&!C&&!B&&A)||(!D&&!C&&B&&A)||(!D&&C&&!B&&!A)||(!D&&C&&!B&&A)||(!D&&C&&B&&A)||(D&&!C&&!B&&A); 
f=(!D&&!C&&!B&&A)||(!D&&!C&&B&&!A)||(!D&&!C&&B&&A)||(!D&&C&&B&&A); 
g=(!D&&!C&&!B&&!A)||(!D&&!C&&!B&&A)||(!D&&C&&B&&A); 
A = !W;  
B = (!Z&&!X&&W)||(X&&!W);  
C = (!Y&&X&&W)||(Y&&!X)||(Y&&!W);  
D = (W&&X&&Y)||(!W&&Z); 
digitalWrite(2,a); 
digitalWrite(3,b); 
digitalWrite(4,c);
digitalWrite(5,d); 
digitalWrite(6,e); 
digitalWrite(7,f); 
digitalWrite(8,g);  
delay(1000);  
W=A;  
X=B;  
Y=C;  
Z=D;
} 
