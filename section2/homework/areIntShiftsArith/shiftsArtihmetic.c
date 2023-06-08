#include <stdio.h>
#include <stdint.h>

int is_right_shift_arithmetic() {
  int num = -10;
  num >>= 31;
  num &= 1;
  return num;
}

int main() {

  printf("\n%d\n", is_right_shift_arithmetic());

}
