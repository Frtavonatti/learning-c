#include <stdio.h>

// Exercise 1.8: Count blanks, tab and newlines

// [ ] Pending review
// Escape sequences: \n = newline || \t = tab || \b = backspace || \ = double quote || \\ backslash itself  
int main() 
{
  int blank = 0, tab = 0, newline = 0;

  int c = getchar(); 
  for (int i = 0; i < c; i++) {
    if (c = '\n') {
      newline++;
    } else if (c = '\t') {
      tab++;
    } else if (c = ' ') {
      blank++;
    }

    getchar();
  }
  printf("%3.0d, %3.0d, %3.0d", blank, tab, newline);
}