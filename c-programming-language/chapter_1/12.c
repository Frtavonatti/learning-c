#include <stdio.h>

// [ ] Pendieng Review

#define IN  1
#define OUT 0

// Exercise 12: write a program that prints its input one word per line
int main ()
{
  int c, state;

  state = OUT;
  c = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      putchar('\n');
      state = OUT;
    } else {
      putchar(c);
      state = IN;
    }
  }

  return 0;
}