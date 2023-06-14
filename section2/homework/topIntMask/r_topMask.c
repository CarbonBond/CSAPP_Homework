#include <stdio.h>
int leftmost_one(unsigned x) {

  //Set all bits to the right of the leftmost bit.
  x |= x >> 1;
  x |= x >> 2;
  x |= x >> 4;
  x |= x >> 8;
  x |= x >> 16;

  //Shifting, then adding 1 gets mask. Conditional checks for no set bits. 
  return (x >> 1) + (x != 0);
}

int main() {
  unsigned num;
  scanf("%x", &num);

  printf("\n%x\n", leftmost_one(num));
}
