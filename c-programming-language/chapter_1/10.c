#include <stdio.h>

// Exercise 1.10: Copy input to its output replacing each tab by \t, each backspace by \b and each backslash by \\.
int main() 
{
  int c;

  // Use ctrl + D (linux) / ctrl + Z (windows) to end the execution of the program (EOF)
  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      putchar('\\');
      putchar('t');
    } else if (c == '\b') {
      putchar('\\');
      putchar('b');
    } else if (c == '\\') {
      putchar('\\');
      putchar('\\');
    } else {
      putchar(c);
    }
  }

  return 0;
}