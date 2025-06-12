#include <stdio.h> 

// Exercise 1.9: Copy input to its output replacing ech string of one or more blanks by a single blank
int main() 
{
  int c;
  int prev_blank = 0; 

  // Use ctrl + D (linux) / ctrl + Z (windows) to end the execution of the program (EOF)
  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      if (!prev_blank) {
        putchar(' ');
        prev_blank = 1;
      }
      // If the next char is also a blank, skip printing
    } else {
      prev_blank = 0;
      putchar(c);
    }
  }
  
  return 0;
}