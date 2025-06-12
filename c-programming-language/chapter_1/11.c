#include <stdio.h>

#define IN  1
#define OUT 0

// Exercise 11: count lines, words and characters in input
int main ()
{
  int c, nl, nw, nc, state;

  state = OUT;
  nl = nw = nc = 0;

  // Use ctrl + D (linux) / ctrl + Z (windows) to end the execution of the program (EOF)
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t')
      state = OUT;
      if (c == '\n')
        ++nl;
    else {
      ++nc; // only count a char if its not a separator 
      if (state == OUT) {
        state = IN;
        ++nw;
      }
    }
  }

  printf("Newlines: %d, Words: %d, Characters: %d\n", nl, nw, nc);
  return 0;
}