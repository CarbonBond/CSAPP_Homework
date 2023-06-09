#include <stdio.h>
#include <stdint.h>

/*
 * EXTRA RULES
 * 
 * Forbidden:
 *  - Right Shift
 *  - Division
 */

unsigned srl(unsigned x, int k) {
  /* Perform shift arithmetically */
  unsigned xsra = (int)x >> k;

  int dataSize = sizeof(x) * 8;

  //Bits that were not shifted in
  unsigned significantBits = dataSize - k;
  
  //Set the highest important bit
  unsigned singleBitSet = 1 << (significantBits - 1);
  
  //Set the remanding zeros to create mask
  unsigned bitMask = singleBitSet | ( singleBitSet - 1 );

  // Mask important bits.
  return xsra & bitMask;
}

int sra(int x, int k) {
  /* Perform shift logically */
  int xsra = (unsigned)x >> k;

  int dataSize = sizeof(x) * 8;

  //Bits that were not shifted in
  unsigned significantBits = dataSize - k;
  
  //Set the highest important bit, which is also sign bit location
  unsigned singleBitSet = 1 << (significantBits - 1);

  //Gets if sign bit is set
  unsigned signBitLocation = xsra & singleBitSet;

  //shift up signbit 
  unsigned signbit = signBitLocation << k;

  uint32_t checkForZero = 1 ^ (((signbit& -signbit) - 1) >> 31) & 1;

  uint32_t test = ~signbit + checkForZero;

  //TODO(carbon): set remanding 
  //If signbit is Set,  the remanding zeros get set, otherwise mask is 0 
  unsigned bitMask = ~(~signbit + checkForZero);
  
  // get top half to mask out lower set bits
  unsigned mask =  bitMask << significantBits;


  // Mask important bits.
  return xsra | mask;
}

int main() {
  printf("\n Result: %X\n", sra(0x12345678, 12));
  printf("\n Result: %X\n", sra(0xD7654321, 16));
}
