#include <stdint.h>
#include <stdio.h>

int replaceByte(int number, uint8_t replacement, int position) {
  int result = 0;

  int positionMask = 0xFF;
  positionMask <<= position * 8;

  result = (number & ~positionMask) | ((uint32_t)replacement << position*8);
  return result;
}

int main() {
  int number, replacement, position;
  scanf("%X %X %X", &number, &replacement, &position);

  printf("\n%X\n", replaceByte(number, replacement, position));

  return 0;
}
