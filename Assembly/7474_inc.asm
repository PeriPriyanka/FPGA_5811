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

ldi r20, 0b00001000
mov r3, r20
and r3, r16
lsr r3
lsr r3
lsr r3

ldi r20, 0b00000100
mov r2, r20
and r2, r16
lsr r2
lsr r2

ldi r20, 0b00000001
mov r1, r20
and r1, r16

ldi r20, 0b00000010
mov r0, r20
and r0, r16
lsr r0

ldi r20, 0b00000001

mov r7, r20
eor r7, r3

mov r6, r20
eor r6, r2

mov r5, r20
eor r5, r1

mov r4, r20
eor r4, r0

mov r12, r4
and r12, r1
and r12, r7

mov r11, r5
and r11, r0

mov r10, r1
and r10, r0
and r10, r6

mov r9, r4
and r9, r2

mov r8, r5
and r8, r2



mov r18, r1
and r18, r0
and r18, r2

mov r19, r5
and r19, r3

or r12, r11
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
