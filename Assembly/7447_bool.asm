
.include "/Users/Priyanka/assembly/m328Pdef/m328Pdef.inc"
ldi r16, 0b00111100 ;identifying output pins 2,3,4,5
out DDRD,r16		;declaring pins as output

ldi r17,0b00000000	;W	
ldi r18,0b00000000	;X
ldi r19,0b00000001	;Y
ldi r21,0b00000000	;Z
ldi r20,0b00000001; loading 1
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



