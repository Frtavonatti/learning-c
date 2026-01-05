#include <stdio.h>
#include <string.h>

char newarr[100];
void itob (int n, char s[], int b);
char itoc (int n, int b);
void reverse (char inv[], char arr[]);
// int pwr (int n, int  e);

/*
 * Exercise 3-5:
 * Write the function itob(n, s, b) that converts the integer n into a base b character representation in the string s.
 * In particular, itob(n, s, 16) formats n as a hexadecimal integer in s.
 * The base b can be any value from 2 to 36.
 */

void main () {
  itob(255, newarr, 16);  // expected: #FF
  itob(100, newarr, 10);  // expected: 100 
  itob(282, newarr, 16);  // expected: #11A
  itob(31, newarr, 2);    // expected: 11111
  itob(255, newarr, 8);   // expected: 377
}

void itob (int n, char s[], int b) {
  char inverse[32];
  int i = 0;
  int mod;

  if (n == 0)
    inverse[i++] = itoc(0, b);

  while (n > 0) {
    mod = n % b;
    n /= b;
    inverse[i++] = itoc(mod, b);
  }

  if (b == 16)
    inverse[i++] = '#';
  inverse[i] = '\0';

  reverse(inverse, s);
  printf("newarr: %s\n\n", s); 
}

void reverse (char inv[], char arr[]) {
  int i, j;
  j = strlen(inv) - 1;
  for (i = 0; j >= 0; i++, j--) {
    arr[i] = inv[j];
  }
  arr[i] = '\0';
}

char itoc (int n, int b) {
  if (n > 9) {
    return 'A' + (n - 10);
  } else {
    return '0' + n;
  }
}

// int pwr (int n, int e) {
//   int r = 1;
//   for (; e > 0; e--)
//     r *= n;
//   return r;
// }
