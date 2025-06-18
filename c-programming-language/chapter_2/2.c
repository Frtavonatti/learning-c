#include <stdio.h> 

#define lim 100

// - [ ] PENDING REVIEW
// Exercise 2.2: Write a loop equivalent to the for loop above without using && or ||
int example () {
  int c;
  char s[10];

  for (int i = 0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i) 
    s[i] = c;

  for (int i = 0; i < 10; ++i)
    printf("%c", s[i]);
  
  return 0;
}

int solution1 () {
  int c;
  char s[10];

  for (int i = 0; i < lim-1 == ((c=getchar()) != '\n') == (c != EOF); ++i) 
    s[i] = c;

  for (int i = 0; i < 10; ++i)
    printf("%c", s[i]);
  
  return 0;
}

int solution2 () {
  int c;
  char s[10];

  for (int i = 0; ; ++i) {
    if (i >= lim-1) 
      break;
    if ((c=getchar()) == '\n')
      break;
    if (c == EOF)
      break;
    s[i] = c;
  }

  for (int i = 0; i < 10; ++i)
    printf("%c", s[i]);
  
  return 0;
}

int main () {
  solution1();
  solution2();
  
  return 0;
}