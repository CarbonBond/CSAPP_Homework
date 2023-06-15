
/* Can X be represented in N bits? */
#include <stdio.h>

void print_bits(unsigned num) {
  for(int i = 32; i > 0; i--) {
    printf("%d", (num & 0x80000000) != 0); 
    num <<= 1;
  }
}

int fits_bits(int x, int n) {

  int nthBit = (1 << (n-1));
  
  //
  int mask1 = x | (x >> 1);
  mask1 |= mask1 >> 2;
  mask1 |= mask1 >> 4;
  mask1 |= mask1 >> 8;
  mask1 |= mask1 >> 16;
  mask1 += 1;

  int nComplement = ~x + 1;

  int mask2 = nComplement ;
  mask2 |= mask2 >> 2;
  mask2 |= mask2 >> 4;
  mask2 |= mask2 >> 8;
  mask2 |= mask2 >> 16;
  mask2 += 1;
  
  int signBitLocation = (mask1 | mask2);
  int mask = (signBitLocation | (signBitLocation - 1)) >> 1;

  int doesFit = (mask & nthBit) == 0;

  return doesFit;
}

int main() {
  int num, bits;
  scanf("%d %d", &num, &bits);

  printf("\n%d\n", fits_bits(num, bits));
}
