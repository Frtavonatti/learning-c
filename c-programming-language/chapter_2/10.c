#include <stdio.h>
#include <string.h>

/* Exercise 2.10: Rewrite the function lower, which converts upper case letters to lower case, with a conditional expression instead of if-else. */

void lower (char arr[]);
char str[] = "HeLLo WoRLd";

void main () {
  lower(str);
  printf("%s\n", str);
}

void lower (char arr[]) {
  int i = 0;
  char c;

  while (c != '\0') {
    c = arr[i];
    (c <= 'Z' && c != ' ') ? arr[i] = c + ('a' - 'A') : c;
    i++;
  }
}
