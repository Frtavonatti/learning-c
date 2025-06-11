#include <stdio.h>

// [ ] Pendieng Review

#define IN  1
#define OUT 0

// Exercise 11
/* count lines, words and characters in input */
int main ()
{
  int c, nl, nw, nc, state;

  state = OUT;
  nl = nw = nc = 0;

  while ((nc = getchar()) != EOF) {
    ++nc;
    if (nc == '\n')
      ++nl;
    if (nc == ' ' || nc == '\n' || nc == '\t') {
      state = OUT;
    } else {
      state = IN;
      ++nw;
    }
  }

  printf("%d, %d, %d\n", nl, nw, nc);
  return 0;
}