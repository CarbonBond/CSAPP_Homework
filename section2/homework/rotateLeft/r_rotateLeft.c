#include <stdio.h>

unsigned rotate_left(unsigned x, int n){
  unsigned rightBits = x >> ((sizeof(x) * 8) - n);
  unsigned leftBits = x << n;
  return rightBits | leftBits;
}

int main(){
  unsigned num, shift;
  scanf("%x %d", &num, &shift);

  printf("\n%x\n", rotate_left(num, shift));
}
