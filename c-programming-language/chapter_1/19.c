#include <stdio.h>
#define MAXLINES 1000

int get_line(char str[], int lim);
void reverse(char input[], char reversed[], int last_index);

// Exercise 1.19: Write a function reverse(s) that reverses the character string s. Use it to write a program that reverses its input a line at a time.
int main() {
  char input[MAXLINES];
  char reversed[MAXLINES];
  int len = get_line(input, MAXLINES);
  int last_index = len - 1;

  while (input[last_index] == ' ' || input[last_index] == '\t' || input[last_index] == '\n')
    --last_index;
  
  if (input[last_index + 1] == '\n') /* delete new line from input */
    input[last_index + 1] = '\0';

  reverse(input, reversed, last_index);

  return 0;
}

void reverse(char input[], char reversed[], int last_index) {
  int j = last_index;
  if (last_index >= 0) {
    for (int i = 0; i <= last_index; i++) {
      reversed[j] = input[i];
      j--;
    }
    reversed[last_index + 1] = '\0';
    printf("Original array: %s\n", input);
    printf("Reversed array: %s\n", reversed);
  } else {
    reversed[0] = '\0';
    printf("Error: No characters to reverse. Please enter some input.\n");
  }
}

int get_line(char str[], int lim) {
  int i = 0, c;
  while (i < lim && (c = getchar()) != EOF && c != '\n') {
    str[i++] = c;
  }
  if (c == '\n') {
    str[i++] = c;
  }
  str[i] = '\0';
  return i;
}