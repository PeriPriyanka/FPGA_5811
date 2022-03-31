
.include "/Users/Priyanka/assembly/m328Pdef/m328Pdef.inc"
ldi r17, 0b11000011 ; identifying input pins 10,11,12,13
	out DDRB,r17		; declaring pins as input
	ldi r17, 0b11111111 ;
	out PORTB,r17		; activating internal pullup for pins 10,11,12,13  
	in r17,PINB

ldi r16, 0b00111100 ;identifying output pins 2,3,4,5
out DDRD,r16		;declaring pins as output
lsr r17
lsr r17
mov r16, r17
ldi r20,0b00000001
and r17,r20 ;W
mov r18,r16
lsr r18
and r18, r20 ;X
mov r19,r16
lsr r19
lsr r19
and r19,r20 ;Y
mov r21, r16
lsr r21
lsr r21
lsr r21
and r21, r20 ;Z
mov r0,r20
mov r22,r17 
eor r22,r0 ;value of A
mov r23,r18
eor r23,r0
mov r24,r21
eor r24,r0
and r23,r24
and r23,r17
mov r24,r22
and r24,r18
or r23,r24 ;value of B
lsl r23
mov r24,r19
eor r24,r0
and r24,r18
and r24,r17
mov r25,r18
eor r25,r0
and r25,r19
mov r26,r22
and r26,r19
or r24,r25
or r24,r26 ;value for C
lsl r24
lsl r24
mov r25, r17
and r25,r18
and r25,r19
mov r26,r22
and r26,r21
or r25,r26 ;Value for D
lsl r25
lsl r25
lsl r25
ldi r16, 0b00000000
or r16,r22
or r16,r23
or r16,r24
or r16,r25
lsl r16
lsl r16

out PORTD,r16
;writing output to pins 2,3,4,5

Start:
rjmp Start



