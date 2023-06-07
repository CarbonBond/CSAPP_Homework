#include <stdio.h>

int replaceLowerByte(int a, int b) {
  int result = (a & 0xFF) | (b & ~0xFF);
  return result;
}

int main() {
  int numA; 
  int numB;

  scanf("%x %x", &numA, &numB);

  printf("result %08X\n", replaceLowerByte(numA,numB));
}

