#include <stdio.h>

// Exercises 1.6-1.7
int main() 
{
  int c = getchar();

  while(c !=  EOF) {
    putchar(c);
    c = getchar();
  }

  int isEnd = getchar() != EOF;
  printf("%d, EOF: %d", isEnd, EOF);
}