// Exercise 1.16: Revise the main routine of the longest-line program so it will correctly print the length of arbitrary long input lines and as much as possible of the text
#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);
void copy(char from[], char to[]);

// PENDING REVIEW
int main() {
  int max = 0;    /* max length so far */
  int len;        /* length of the current line */
  int this_len;   /* total length of the current line (may be > MAXLINE) */
  char line[MAXLINE];    /* current line */
  char longest[MAXLINE]; /* stores the longest line */

  while ((len = get_line(line, MAXLINE)) > 0) {
    this_len = len;

    while (line[len-1] != '\n') {
      int extra = get_line(line, MAXLINE); printf("EXTRA: %d", extra);
      this_len += extra;
      len = extra;
    }

    if (this_len > max) {
      max = this_len;
      copy(line, longest);
    }
  }

  if (max > 0)
    printf("The longest line so far is: %s and his length is %d", longest, max);
  
  return 0;
}

void copy(char from[], char to[]) {
  int i = 0;
  while(from[i] != '\0') {
    to[i] = from[i];
    ++i;
  }
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
