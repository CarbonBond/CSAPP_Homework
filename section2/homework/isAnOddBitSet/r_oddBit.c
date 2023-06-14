
#include <stdio.h>
int any_odd_one(unsigned x) {
  x = x & 0x55555555;
  return x != 0;
}

int main() {
  unsigned num;
  scanf("%d", &num);

  printf("\n%d\n", any_odd_one(num));
}
