#include <stdio.h>
typedef unsigned packed_t;

int xbyte(packed_t word, int bytenum);

int main() {

  int num, bytenum;
  scanf("%x %d", &num, &bytenum);

  int number = 0x80000000 ;

  printf("\n%x\n", xbyte(num, bytenum));
  return 0;
}

/* Failed example 
int xbyte(packed_t word, int bytenum) {
  return (word >> (bytenum << 3)) & 0xFF;
}
 
Q: What is wrong with the above code. 

A: this doesn't pack sign bits. 

Fix example with left & right shifts & one subtraction
*/


int xbyte(packed_t word, int bytenum) {
  return (int)(word << (24 - (bytenum << 3))) >> 24;
}

