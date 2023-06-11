/* The following code runs on some machines 

int bad_int_size_is_32() {

  // Set most significant bit (msb) of 32-bit machine 
  int set_msb = 1 << 31;

  // Shift past msb of 32-bit word 
  int beyond_msb = 1 << 32;

  // set_msb is nonzero when word size > 32
  // beyond_msb is zero when word size <= 32
  return set_msb && !beyond_msb;
}

 * The above function gives us an error on 32bit SUN SPARC
 *  warning: left shift count >= width of type
 *
 *  Question A: 
 *    In what whay does our code fail to comply with the C standard?
 *  Answer:
 *    Section 6.5.7p3 details shifting by an amount greator than he bit width 
 *    of the type causes undefined behavior.
 *
 *  B: Modifiy code to run properly on any machine that sizeof(int) is 32. 
 *  C: Modifiy code to run properly on any machine that sizeof(int) is 16. 
 *
 *  Rule: Cannont use the "sizeof" operator
 *
 */

#include <stdio.h>

/* The following code runs on 32bit machines */
int int_size_is_32() {
  /* Set most significant bit (msb) of 32-bit machine */
  int set_msb = 1 << 31;
  /* Shift past msb of 32-bit word */
  int beyond_msb = 0xFFFFFFFF + 1; 

  /* set_msb is nonzero when word size > 32
   * beyond_msb is zero when word size <= 32 */
  return set_msb && !beyond_msb;
}

/* The following code runs on 16bit machines */
int int_size_is_16() {
  /* Set most significant bit (msb) of 32-bit machine */
  int set_msb = 1 << 15;
  /* Shift past msb of 32-bit word */
  int beyond_msb = 0xFFFF + 1; 

  /* set_msb is nonzero when word size > 32
   * beyond_msb is zero when word size <= 32 */
  return set_msb && !beyond_msb;
}
/* Testing if 16bit size works (don't have access to 16bit int machine) */
short short_size_is_16() {
  /* Set most significant bit (msb) of 32-bit machine */
  short set_msb = (short)(1 << 15);
  /* Shift past msb of 32-bit word */
  short beyond_msb = (short)(0xFFFF + 1); 

  /* set_msb is nonzero when word size > 32
   * beyond_msb is zero when word size <= 32 */
  return set_msb && !beyond_msb;
}

int main() {
  printf("int is 32: %d, int is 16: %d, short is 16: %d", int_size_is_32(), int_size_is_16(), short_size_is_16());
}
