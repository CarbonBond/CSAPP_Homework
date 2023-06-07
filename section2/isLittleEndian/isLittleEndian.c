#include <stdio.h>
#include <stdint.h>


int is_little_endian() {
  int result = 0;
  uint16_t num = 1;
  uint8_t* bytes = (uint8_t*)&num;
  bytes++;
  result = !(*bytes);
  return result;
}

int main() {

  printf("Is little endian: %d\n", is_little_endian());
  return 0;
}
