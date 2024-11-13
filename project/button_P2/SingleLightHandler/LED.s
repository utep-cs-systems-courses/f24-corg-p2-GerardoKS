  .arch masp430g2553
  .p2align 1.0
  .text
  .global GreenOn
  .global RedOn
  .extern P1OUT
  .extern P1DIR
  
GreenOn: 
  sub #6, r0
  mov 0(r0), #0b00010001
  mov 2(r0), #0b00010000
  mov 4(r0), #0b00000001
  bis 0(r0), P1DIR
  xor 4(r0), P1OUT
  bis 2(r0), P1OUT
  add #6, r0
  pop r0  

RedOn : 
  sub #6, r0
  mov 0(r0), #0b00010001
  mov 2(r0), #0b00010000
  mov 4(r0), #0b00000001
  bis 0(r0), P1DIR
  xor 2(r0), P1OUT
  bis 4(r0), P1OUT
  add #6, r0
  pop r0
