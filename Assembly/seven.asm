
.include "/Users/Priyanka/assembly/m328Pdef/m328Pdef.inc"

;using assembly language for 
;displaying number on
;seven segment display


  
;Configuring pins 2-7 (PD2-PD7) of Arduino
;as output
  ldi r16,0b11111100
  out DDRD,r16
;Configuring pin 8 (PB0) of Arduino
;as output 
  ldi r16,0b00000001
  out DDRB,r16
;Writing the number 0 on the 
;seven segment display
;  ldi r17,0b00000000
 ; out PortD,r17
  
  ;ldi r17,0b00000001
  ;out PortB,r17
  ;Writing the number 1 on the 
;seven segment display
;  ldi r17,0b11100100
 ; out PortD,r17
  
  ;ldi r17,0b00000001
  ;out PortB,r17
  ;Writing the number 2 on the 
;seven segment display
  ;ldi r17,0b10010000
  ;out PortD,r17
  
  ;ldi r17,0b00000000
  ;out PortB,r17
  ;Writing the number 3 on the 
;seven segment display
;  ldi r17,0b11000000
 ; out PortD,r17
  
  ;ldi r17,0b00000000
  ;out PortB,r17
  ;Writing the number 4 on the 
;seven segment display
;  ldi r17,0b01100100
 ; out PortD,r17
  
  ;ldi r17,0b00000000
  ;out PortB,r17
  ;Writing the number 5 on the 
;seven segment display
;  ldi r17,0b01001000
 ; out PortD,r17
  
  ;ldi r17,0b00000000
  ;out PortB,r17
  ;Writing the number 6 on the 
;seven segment display
;  ldi r17,0b00001000
 ; out PortD,r17
  
  ;ldi r17,0b00000000
  ;out PortB,r17
  ;Writing the number 7 on the 
;seven segment display
;  ldi r17,0b11100000
 ; out PortD,r17
  
  ;ldi r17,0b00000001
  ;out PortB,r17
  ;Writing the number 8 on the 
;seven segment display
  ;ldi r17,0b00000000
  ;out PortD,r17
  
 ; ldi r17,0b00000000
 ; out PortB,r17
  ;Writing the number 8 on the 
;seven segment display
  ldi r17,0b01000000
  out PortD,r17
  
  ldi r17,0b00000000
  out PortB,r17
Start:
  rjmp Start
