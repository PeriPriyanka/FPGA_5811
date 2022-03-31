
.include "/Users/Priyanka/assembly/m328Pdef/m328Pdef.inc"
ldi r16, 0b00111100 ;identifying output pins 2,3,4,5
	out DDRD,r16		;declaring pins as output
;	ldi r16,0b00000000	;loading the number 0 in binary
;	out PORTD,r16		;writing output to pins 2,3,4,5
;ldi r16,0b00000100	;loading the number 1 in binary
;	out PORTD,r16		;writing output to pins 2,3,4,5
;	ldi r16,0b00001000	;loading the number 2 in binary
;	out PORTD,r16		;writing output to pins 2,3,4,5
;	ldi r16,0b0001100	;loading the number 3 in binary
;	out PORTD,r16		;writing output to pins 2,3,4,5
	;ldi r16,0b00010000	;loading the number 4 in binary
	;out PORTD,r16		;writing output to pins 2,3,4,5
	;ldi r16,0b00010100	;loading the number 5 in binary
	;out PORTD,r16		;writing output to pins 2,3,4,5
;ldi r16,0b00011000	;loading the number 6 in binary
;	out PORTD,r16		;writing output to pins 2,3,4,5	

;ldi r16,0b00011100	;loading the number 7 in binary
;	out PORTD,r16		;writing output to pins 2,3,4,5
ldi r16,0b00100000	;loading the number 8 in binary
	out PORTD,r16		;writing output to pins 2,3,4,5


	;ldi r16,0b00100100	;loading the number 9 in binary
	;out PORTD,r16		;writing output to pins 2,3,4,5
	
Start:
	rjmp Start
