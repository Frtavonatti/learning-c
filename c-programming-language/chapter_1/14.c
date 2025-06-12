#include <stdio.h>

// [ ] Pendieng Review // Not completed

// Exercise 14: Write a program to print a histogram of frecuencies of different characters in its input. 
int main () {
  int ndigit[10];
  int c, nwhite, nother;

  nwhite = nother = 0;

  // Initialize array values
  for (int i = 0; i < 10; ++i) {
    ndigit[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    if (c > '0' && c < '9') {
      ++ndigit[c-'0'];
    } else if (c == ' ' || c == '\n' || c == '\t') {
      ++nwhite;
    } else {
      ++nother;
    }
  }

  printf("Digits:");
  for (int i = 0; i < 0; ++i) {
    printf(" %d", ndigit[i]); // check array printing
  }
  printf(", Whites: %d, Others: %d\n", nwhite, nother);

  return 0;
}