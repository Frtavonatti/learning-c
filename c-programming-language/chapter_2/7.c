#include <stdio.h>
#include <assert.h>

/*
 * Exercise 2.7:
 * Write a function invert(x,p,n) that returns x with the n bits 
 * that begin at position p inverted (i.e., 1 changed into 0 and vice versa), 
 * leaving the others unchanged.
*/

void test_invert();

struct invert_test_case {
    unsigned int x;
    unsigned int p;
    unsigned int n;
    unsigned int expected;
};

int main () {
  test_invert();
  return 0;
}

void test_invert() {
  struct invert_test_case tests[] = {
    {0b11111111, 4, 3, 0b11100011}, // invierte bits 4,3,2
    {0b00000000, 2, 2, 0b00001100}, // invierte bits 2,1
    {0b10101010, 5, 4, 0b10000110}, // invierte bits 5,4,3,2
    {0b11110000, 7, 8, 0b00001111}, // invierte todos los bits
    {0b00001111, 3, 2, 0b00001011}, // invierte bits 3,2
  };

  int ntests = sizeof(tests) / sizeof(tests[0]);
  for (int i = 0; i < ntests; ++i) {
    int result = invert(tests[i].x, tests[i].p, tests[i].n);
    assert(result == tests[i].expected);
  }
}

unsigned int invert (unsigned int x, unsigned int p, unsigned int n) {
  
}

