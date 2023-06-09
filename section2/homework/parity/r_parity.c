#include <stdio.h>
#include <stdint.h>

int oddBitCheck(uint32_t num) {
  num ^= (num >> 1);
  num ^= (num >> 2);
  num ^= (num >> 4);
  num ^= (num >> 8);
  num ^= (num >> 16);

  return num & 1;
}

int main() {
  uint32_t number;
  scanf("%d", &number);

  printf("\n%x\n", oddBitCheck(number));
}
