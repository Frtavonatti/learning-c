// Exercise 1.17: Write a program to print all input lines that are longer than 80 characters
#include <stdio.h>
#define MAXLINE 1000    /* max ammount of chars that each str can have */
#define MAXARRAY 20     /* max ammount of strings that long_lines can store */

int get_line(char line[], int maxline);
void append_str(char str[], char to[MAXARRAY][MAXLINE]);
int str_len(char str[]);

char long_lines[MAXARRAY][MAXLINE] = { { '\0' } };

char test_lines[3][MAXLINE] = {
  "This is a short line.",
  "This line is exactly eighty-one characters long: 123456789012345678901234567890123456789012345678901234567890123456789012345678901",
  "Another short line."
};

int main() {
  int limit = 80;  /* limit to compare the lenght of the current line */
  int len;         /* length of the current line */
  char line[MAXLINE];    /* current line */

  while ((len = get_line(line, MAXLINE)) > 0) { 
    if (len > limit) {
      append_str(line, long_lines);
    }
  }

  // if there is no input on get_line, use test_lines array
  if (len == 0) { 
    for(int i=0; i<3; ++i) {
      if (str_len(test_lines[i]) > 80)
        append_str(test_lines[i], long_lines);
    }
  }

  for (int j=0; j<MAXARRAY; ++j) {
    if (long_lines[j][0] != '\0')
      printf("%s\n", long_lines[j]);
  }
  
  return 0;
}

void copy(char from[], char to[]) {
  int i = 0;
  while(from[i] != '\0') {
    to[i] = from[i];
    ++i;
  }
}

void append_str(char str[], char to[MAXARRAY][MAXLINE]) {
  int i = 0;
  while (i < MAXARRAY && to[i][0] != '\0')
    ++i;
  if (i < MAXARRAY)
    copy(str, to[i]);
} 

int str_len(char str[]) {
  int i = 0;
  while (str[i] != '\0')
    ++i;
  return i;
}

/* copy input to an array and return length */
int get_line(char str[], int lim) {
  int c, i;
  for (i = 0; i < lim && ((c=getchar()) != EOF) && c != '\n'; ++i){
    str[i] = c;
  if (c == '\n')
    str[i] = c;
    ++i;
  }
  str[i] = '\0';
  return i;
}