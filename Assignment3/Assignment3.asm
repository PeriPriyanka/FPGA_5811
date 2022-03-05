.include "/Users/Priyanka/assembly/m328Pdef/m328Pdef.inc"
ldi r17, 0b11110011 ; identifying input pins 2,3
	out DDRD,r17		; declaring pins as input
	ldi r17, 0b11111111 ;
	out PORTD,r17		; activating internal pullup for pins 2,3  
	in r17,PIND

ldi r16, 0b00100000 ;identifying output pins 13
out DDRB,r16		;declaring pins as output
lsr r17
lsr r17
mov r16, r17
ldi r20,0b00000001
and r17,r20 ;V
mov r18,r16
lsr r18
and r18, r20 ;U
mov r0,r20
mov r19,r17
and r19,r18 ; UV
mov r21,r17
eor r21,r20 
and r21,r18 ;UV'
mov r22,r17
eor r22, r20
mov r23, r18
eor r23,r20
and r22, r23 ;U'V'
or r19,r21
or r19,r22 ; U'V'+UV'+UV
mov r21, r17
eor r21, r20
or r21, r18 ;U+V'
sub r21,r19 
ldi r16,0b00100000
breq loop
ldi r16, 0b00000000
out PORTB,r16
loop:
out PORTB,r16
;writing output to pins 13

Start:
rjmp Start




