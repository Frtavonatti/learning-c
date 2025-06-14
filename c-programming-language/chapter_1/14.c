#include <stdio.h>

// Exercise 14: Write a program to print a histogram of frecuencies of different characters in its input. 
int main () {
  int ndigit[128];
  int c, nwhite = 0, nother = 0;

  for (int i = 0; i <= 'z'; ++i)
    ndigit[i] = 0;

  // Use ctrl + D (linux) / ctrl + Z (windows) to end the execution of the program (EOF)
  while ((c = getchar()) != EOF) {
    if (c >= '0' && c <= 'z')
      ++ndigit[c];
    else if (c == ' ' || c == '\n' || c == '\t')
      ++nwhite;
    else
      ++nother;
  }

  printf("Digits: [");
  for (int i = 0; i < 123; ++i)
    if(i == 122)
      printf("%c: %d]\n", i, ndigit[i]);
    else if(ndigit[i] > 0)
      printf("%c: %d, ", i, ndigit[i]);

  printf("Whites: %d, Others: %d\n", nwhite, nother);

  return 0;
}