#include <stdio.h>
int maskNumBits(int num) {

  //Shift bit to the top location
  // num = 6, x = 0010_0000
  int x = 1 << (num - 1);
  //Set a lower bits to 1
  x = x | (x-1);

  return x;
}

int main() {
  int num;
  scanf("%x", &num);
  printf("\n%x\n", maskNumBits(num));
}

