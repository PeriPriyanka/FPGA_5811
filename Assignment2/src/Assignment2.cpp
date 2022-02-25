#include <Arduino.h>
int u=0,v=0;
void setup() {
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,INPUT);
  pinMode(9,INPUT);  
}

void loop() {
  u=digitalRead(10);
  v=digitalRead(9);
  if((!u&&!v)||(!u&&v)||(u&&v)==1)
  {
    digitalWrite(12,LOW);
  }
  else
  {
    digitalWrite(12,HIGH);
  }
  if(((!u)||v)==1)
  {
    digitalWrite(11,LOW);
  }
  else
  {
    digitalWrite(11,HIGH);
  }
  if((!u&&!v)||(!u&&v)||(u&&v)==((!u)||v))
  {
    digitalWrite(13,HIGH);
  }
  else
  {
    digitalWrite(13,LOW);
  }

}
