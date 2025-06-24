#include <stdio.h>
#include <stdbool.h>
#define MAXLINES   1000

int get_line(char s[], int lim);
int str_len(char str[]);

// Exercise 1.18: Write a program to remove trailing blanks and tabs from each line of input and to delete entirely blank lines 
int main(){
  int len;
  char store_arr[MAXLINES];
  char new_arr[MAXLINES];

  len = get_line(store_arr, MAXLINES);

  int end = len - 1;
  while (end >= 0 && (store_arr[end] == ' ' || store_arr[end] == '\t' || store_arr[end] == '\n')) {
    end--;
  }

  if (end >= 0) {
    for (int i = 0; i <= end; i++) {
      new_arr[i] = store_arr[i];
    } 
    new_arr[end + 1] = '\0';
  }

  printf("Copied input into array: %s", store_arr);
  printf("New array without blanks: %s\n", new_arr);
  printf("Original string length: %d\n", len);
  printf("New string length: %d\n", str_len(new_arr));
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

int str_len(char str[]) {
  int i = 0;
  while (str[i] != '\0') {
    ++i;
  }
  return i;
}