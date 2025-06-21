#include <stdio.h>
#define MAXLINE 1000

/* copy an string */
void copy(char from[], char to[]) {
  int i = 0;
  while(from[i] != '\0') {
    to[i] = from[i];
    ++i;
  }
  to[i] = '\0';
}

/* copy input to an array and return length */
int get_line(char str[], int lim) {
  int c, i;

  for (i = 0; i < lim && ((c=getchar()) != EOF) && c != '\n'; ++i){
    str[i] = c;
    if (c == '\n')
      str[i] = c;
    }
  str[++i] = '\0';

  return i;
}

/* prints the longest line of the input and the length */
int main() {
  int max = 0; /* max length so far */
  int len;     /* length of the current line */
  char line[MAXLINE];    /* current line */
  char longest[MAXLINE]; /* stores the longest line */

  while ((len = get_line(line, MAXLINE) > 0)) {
    if (len > max) {
      max = len;
      copy(line, longest);
    }
  }

  if (max > 0)
    printf("The longest line so far is: %s and his length is %d", longest, max);
  
  return 0;
}