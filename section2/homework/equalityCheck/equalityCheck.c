#include <stdio.h>
#include <stdint.h>

//Cases for true
// 1: Most significant bit is 0
// 2: Least significant bit is 1
// 3: There is a 1 bit 
// 4: There is a 0 bit
//
// Assumming least and most significant bits don't affect case 3 and 4


uint32_t checknum(uint32_t number) {
  
  //Most Significant bit should be 0
  uint32_t mSig = 1 ^ (number >> 31);
    
  //Least Significant bit should be 1
  uint32_t lSig = number & 1;

  uint32_t numberNoSignificant = number & 0x7FFFFFFE;
  //
  //produces 1 if there is a 1 bit set
  uint32_t checkForOne = 1 ^ ((((numberNoSignificant & -numberNoSignificant) - 1) >> 31) & 1);

  //Swapping bits lets us check for "1" again, but will result on if there is a 0
  numberNoSignificant = ~number & 0x7FFFFFFE;
  uint32_t checkForZero = 1 ^ ((((numberNoSignificant & -(numberNoSignificant)) - 1) >> 31) & 1);

  return checkForZero & checkForOne & lSig & mSig;
}

uint32_t main() {

  printf("\nShould Fail: %d\n", checknum(0x80000000)); // Case 1 fails
  printf("\nShould Fail: %d\n", checknum(0x20)); // Case 2 fails
  printf("\nShould Fail: %d\n", checknum(0x1)); // Case 3 Fails 
  printf("\nShould Fail: %d\n", checknum(0x7FFFFFFF)); // Case 4 fails
  printf("\nShould Succeed: %d\n", checknum(0b0000101)); // All truthy
     
  return 0;
}
