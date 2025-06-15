#include <stdio.h>

int power(int b, int e) {
  int n = 1;

  while (e > 0) {
    --e;
    n *= b; 
    printf("e: %d, n: %d\n", e, n);
  }

  return n;
}


int main () {
  printf("%d\n", power(2, 3));
  printf("%d\n", power(5, 3));

  return 0;
}
