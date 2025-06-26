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
      printf("i: %d\n", i); /* delete this print */
      printf("Modulo: %d\n", (TABS - i) % 8); /* delete this print */
      for (int j = 0; j < TABS; j++) {
        str[i++] = ' ';
      }
    }
    else
      str[i++] = c;
  }

  if (c == '\n')
    str[i++] = '\n';

  str[i] = '\0';
}

// 12 % 8 = 4       -> 4 (TAB - mod)
// 17 % 8 = 1       -> 7 (TAB - mod)
// 36 % 8 = 4       -> 4 (TAB - mod)

// TABS - ((TABS - i) % 8)