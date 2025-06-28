#include <stdio.h>
#define MAXLINES 1000
#define TABS     8

/* Exercise 1.20: Write a program detab that replaces tabs in the input with the proper number of blanks
                  to space to the next tab stop. Assume a fixed set of tab stops, say every n colummns.
*/

void get_line_and_detab(char str[], int lim);

int main () {
  char arr[MAXLINES];
  get_line_and_detab(arr, MAXLINES);
  printf("%s", arr);
  return 0;
}

void get_line_and_detab(char str[], int lim) {
  int i = 0, c;

  while ((c = getchar()) != EOF && c != '\n') {
    if (c == '\t') {
      int spaces_to_fill = TABS - (i % TABS);
      for (int j = 0; j < spaces_to_fill; j++) {
        str[i++] = ' ';
      }
    } else
      str[i++] = c;
  }

  if (c == '\n' && i < lim -1)
    str[i++] = '\n';

  str[i] = '\0';
}