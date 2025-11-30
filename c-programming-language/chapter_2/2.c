#include <stdio.h> 

enum { MAXLINE = 40 };

void getline_with_logical_ops() {
  int c;
  char s[MAXLINE] = {0}; // Initializes the array with 0s
  int i;

  for (i = 0; i < MAXLINE-2 && (c=getchar()) != '\n' && c != EOF; ++i) 
    s[i] = c;

  if (c == '\n' && i < MAXLINE - 1)
    s[i++] = '\n';
  s[i] = '\0'; // Null-terminate the string

  printf("Result: %s\n", s);
}

// Exercise 2.2: Write a loop equivalent to the for loop above without using && or ||
void getline_without_logical_ops() {
  int c;
  char s[MAXLINE] = {0};
  int i;

  for (i = 0; ; ++i) {
    if (i >= MAXLINE-2) 
      break;

    c = getchar();
    if (c == EOF)
      break;
    if (c == '\n')
      break;
    s[i] = c;
  }

  if (c == '\n' && i < MAXLINE - 1)
    s[i++] = '\n';
  s[i] = '\0';

  printf("Result: %s", s);
}

int main () {
  printf("Test 1 - with logical operators:\n");
  getline_with_logical_ops();

  printf("Test 2 - without logical operators:\n");
  getline_without_logical_ops();
  return 0;
}
