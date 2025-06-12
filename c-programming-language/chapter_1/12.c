#include <stdio.h>

#define IN  1
#define OUT 0

// Exercise 12: write a program that prints its input one word per line
int main ()
{
  int c, state;

  state = OUT;
  c = 0;

  // Use ctrl + D (linux) / ctrl + Z (windows) to end the execution of the program (EOF)
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      if (state != OUT) {
        putchar('\n');
        state = OUT;
      }
    } else {
      putchar(c);
      state = IN;
    }
  }

  return 0;
}