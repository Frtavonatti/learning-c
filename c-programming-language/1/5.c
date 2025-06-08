#include <stdio.h>

int reversefahrenheitToCelsius() {
  float upper, lower, step;
  float fahr, celsius;

  lower = 0;
  upper = 300;
  step = 20;

  for (int fahr = 300; fahr >= lower; fahr = fahr - step) {
    printf("%3.0d\t %3.1f \n", fahr, (fahr - 32.0) * 5.0/9.0);
  }

  return 0;
}

int main() {
  reversefahrenheitToCelsius();
  return 0;
}