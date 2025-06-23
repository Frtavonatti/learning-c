#include <stdio.h>
#define MAXLINES   1000
#define MAXARRAYS  10

int get_line(char s[], int lim)
int str_len(char arr[]);
int arr_len(char arr[][MAXARRAYS]);

// PENDING REVIEW
// Exercise 1.18: Write a program to remove trailing blanks and tabs from each line of input and to delete entirely blank lines 
int main(){
  int c;
  int len, array_len, last;
  char store_arr[MAXLINES][MAXARRAYS];
  char new_arr[MAXLINES][MAXARRAYS];

  // FIX: c is never inicialized inside the loop
  for (int i=0; i < MAXARRAYS && c == '\n'; ++i) 
    get_line(store_arr[i], MAXARRAYS-1);

  array_len = arr_len(store_arr);

  /* copy excluding trailing blank spaces and tabs */
  for (int i=0; i<array_len; ++i) {
    len = str_len(store_arr[i]);
    for (int last = len-1; last >= 0; --last) {
      if (store_arr[i][last] != ' ' && store_arr[i][last] != '\t')
        new_arr[i][last] = store_arr[i][last];
    }
  }

  for(int i=0; i<array_len; ++i) {
    len = str_len(new_arr[i]);
    for (int j=0; j<len; ++j) 
      printf("%c", new_arr[i][j]);
  }
  return 0;
}

int get_line(char s[], int lim) {
  int c, i = 0;
  while (i < lim - 1 && (c = getchar()) != EOF && c != '\n')
    s[i++] = c;
  if (c == '\n')
    s[i++] = c;
  s[i] = '\0';
  return i;
}

int str_len(char arr[]) {
  int i = 0;
  while (arr[i] != '\0')
    ++i;
  return i;
}

int arr_len(char arr[][MAXARRAYS]) {
  int i = 0;
  while (arr[i][0] != '\0' && i < MAXLINES)
    ++i;
  return i;
}