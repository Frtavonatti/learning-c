#include <stdio.h> 

enum { lim = 40 };

int example () {
  int c;
  char s[lim] = {0};
  int i;

  for (i = 0; i < lim-2 && (c=getchar()) != '\n' && c != EOF; ++i) 
    s[i] = c;

  s[i++] = '\n';
  s[i] = '\0'; // Null-terminate the string

  for (int j = 0; j < i; ++j)
    printf("%c", s[j]);
  
  return 0;
}

// Exercise 2.2: Write a loop equivalent to the for loop above without using && or ||
int solution () {
  int c;
  char s[lim] = {0};
  int i;

  for (i = 0; ; ++i) {
    if (i >= lim-1) 
      break;
    if ((c=getchar()) == '\n')
      break;
    if (c == EOF)
      break;
    s[i] = c;
  }

  s[i++] = '\n';
  s[i] = '\0';

  for (int j = 0; j < i; ++j)
    printf("%c", s[j]);
  
  return 0;
}

int main () {
  example();
  solution();
  return 0;
}

// int incorrect_solution () {
//   int c;
//   char s[lim];
//   int i;

//   for (i = 0; i < lim-1 == ((c=getchar()) != '\n') == (c != EOF); ++i) 
//     s[i] = c;
  
//   s[i++] = '\n';
//   s[i] = '\0';

//   for (int j = 0; j < i; ++j)
//     printf("%c", s[j]);
  
//   return 0;
// }