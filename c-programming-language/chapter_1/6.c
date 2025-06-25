#include <stdio.h>

// Exercise 1.6: Verify that the expression getchar() != EOF is 0 or 1.
int main(void) {
  int c;
  printf("Enter a character, then Ctrl+D (Unix) or Ctrl+Z (Windows) to send EOF:\n");
  c = getchar() != EOF;
  printf("getchar() != EOF evaluates to: %d\n", c);
  return 0;
}