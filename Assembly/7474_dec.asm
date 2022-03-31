.include "/Users/Priyanka/assembly/m328Pdef/m328Pdef.inc"
ldi r24, 0b11000000
out DDRD, r24
ldi r24, 0b00100011
out DDRB, r24

start:
sbi PORTB, 5
call wait

in r16, PIND
ldi r31, 0b00111100
and r16, r31
lsr r16
lsr r16

ldi r20, 0b00001000 ;A
mov r3, r20
and r3, r16
lsr r3
lsr r3
lsr r3

ldi r20, 0b00000100 ;B
mov r2, r20
and r2, r16
lsr r2
lsr r2

ldi r20, 0b00000010 ;C
mov r0, r20
and r0, r16
lsr r0

ldi r20, 0b00000001 ;D
mov r1, r20
and r1, r16


ldi r20, 0b00000001

mov r7, r20
eor r7, r3 ;!A

mov r6, r20
eor r6, r2 ;!B

mov r4, r20
eor r4, r0 ;!C

mov r5, r20
eor r5, r1 ;!D

mov r18, r3
and r18, r1; A D
mov r19, r7
and r19, r6
and r19, r5
and r19, r4; !A !B !C !D = W

mov r10, r2
and r10, r1; B D
mov r9, r2
and r9, r0; B C
mov r8, r3
and r8, r5; A !D = X

mov r12, r0
and r12, r1; C D
mov r1, r3
and r11, r5; A !D
mov r21, r2
and r21, r4;
and r21, r5; B !C !D = Y


or r12, r11
or r12, r21
lsl r12

or r10, r9
or r10, r8
lsl r10
lsl r10

or r18, r19
lsl r18
lsl r18
lsl r18

or r18, r10
or r18, r12
or r18, r5

mov r31, r18
ldi r30, 0b00001100
and r31, r30
lsr r31
lsr r31
mov r30, r18
lsl r30
lsl r30
lsl r30
lsl r30
lsl r30
lsl r30

out PORTB, r31
out PORTD, r30

cbi PORTB, 5
sbi PORTB, 5

jmp start
wait:
push r16
push r17
push r18
ldi r16, 0x50
ldi r17, 0x00
ldi r18, 0x00
w0:
dec r18
brne w0
dec r17
brne w0
dec r16
brne w0
pop r18
pop r17
pop r16
ret
