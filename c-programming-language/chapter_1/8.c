#include <stdio.h>

// Exercise 1.8: Count blanks, tab and newlines
int main() 
{
  int blank = 0, tab = 0, newline = 0;
  int c; 

  // Use ctrl + D to end the execution of the program (EOF)
  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      ++newline;
    } else if (c == '\t') {
      ++tab;
    } else if (c == ' ') {
      ++blank;
    }
  }
  printf("Blanks: %d, Tabs: %d, Newlines: %d", blank, tab, newline);
}