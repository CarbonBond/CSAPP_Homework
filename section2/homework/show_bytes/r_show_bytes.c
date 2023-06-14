#include <stdio.h>
#include <stdint.h>

int show_bytes_short(short num) {
  int8_t* bytes = (uint8_t*)&num;

  for (int i = 0; i < sizeof(short); i++) {
    printf("%02X ", (uint8_t)*bytes);
    bytes++;
  }

  printf("\n");
}

int show_bytes_int(int num) {
  int8_t* bytes = (uint8_t*)&num;

  for (int i = 0; i < sizeof(int); i++) {
    printf("%02X ", (uint8_t)*bytes);
    bytes++;
  }

  printf("\n");
}

int show_bytes_double(double num) {
  int8_t* bytes = (uint8_t*)&num;

  for (int i = 0; i < sizeof(double); i++) {
    printf("%02X ", (uint8_t)*bytes);
    bytes++;
  }

  printf("\n");
}

int main() {

  double num; 
  scanf("%lf", &num);

  int32_t minRepresentation = 2;
  int8_t* bytes;

  if (num < INT16_MAX && num > INT16_MIN) {
    show_bytes_short((short)num);
  }
  else if (num < INT32_MAX && num > INT32_MIN){
    show_bytes_short((int)num);
  }
  else {
    show_bytes_double(num);
  }
}


