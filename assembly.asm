.include "/storage/self/primary/digital-design/ide/piosetup/Assembly/m328Pdef.inc"

.cseg
.org    0x0000          ; Reset vector
    rjmp    start

start:
    ; Initialize I/O ports
    ldi     r16, (1 << DDB2)   ; Set Pin 2 (input1) as input
    cbi     DDRD, PD2
    ldi     r16, (1 << DDB3)   ; Set Pin 3 (input2) as input
    cbi     DDRD, PD3
    ldi     r16, (1 << DDB5)   ; Set Pin 13 (output) as output
    sbi     DDRB, PB5

loop:
    ; Read input bits from Pin 2 and Pin 3
    sbic    PIND, PD2            ; Check if Pin 2 is HIGH
    rjmp    input1_high
    sbic    PIND, PD3            ; Check if Pin 3 is HIGH
    rjmp    input2_high

    ; Both inputs are LOW, turn on the LED
    sbi     PORTB, PB5           ; Set Pin 13 HIGH
    rjmp    loop

input1_high:
    sbic    PIND, PD3            ; Check if Pin 3 is HIGH
    rjmp    input2_high

    ; Input 1 is HIGH, turn off the LED
    cbi     PORTB, PB5           ; Set Pin 13 LOW
    rjmp    loop

input2_high:
    ; Input 2 is HIGH, turn off the LED
    cbi     PORTB, PB5           ; Set Pin 13 LOW
    rjmp    loop
