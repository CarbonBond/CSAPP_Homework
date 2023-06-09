Any file prefaced with r_ have followed the following rules 

Specific rules for a question are added at the top of the file. They 
can break the below rules.

## Assumptions 
  - Integers are in 2s complement
  - Right shifts are arithmetic
  - int is **W** bits long
    - File mentions specific value, others all possible values are considered.

## Forbidden:
  - if, while, for, switch, functions, marcos
  - Division, Mod, Multiplication
  - relative comparisons

## Allowed:
  - Bitlevel and Logic operations
  - left and right shifts
    - 0 < shift < **w** -1
  - addition, subtraction
  -  equality and inequality
  - min and max values of int
  - casting
