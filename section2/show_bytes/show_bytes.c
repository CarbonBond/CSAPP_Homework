#include <stdio.h>
#include <stdint.h>

int main() {

  double num; 
  scanf("%lf", &num);

  int32_t minRepresentation = 2;
  int8_t* bytes;

  if (num < INT16_MAX && num > INT16_MIN) {
    minRepresentation = sizeof(uint16_t);
    int16_t number = num;
    bytes = (int8_t*)&number;
  }
  else if (num < INT32_MAX && num > INT32_MIN){
    minRepresentation = sizeof(uint32_t);
    int32_t number = num;
    bytes = (int8_t*)&number;
  }
  else {
    minRepresentation = sizeof(double);
    bytes = (int8_t*)&num;
  }

  for (int i = 0; i < minRepresentation; i++) {
    printf("%02X ", (uint8_t)*bytes);
    bytes++;
  }
  printf("\n");
}
