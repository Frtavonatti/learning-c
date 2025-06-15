#include <stdio.h>

// Exercise 1.15: Rewrite the temperature conversion program to use a function.
float fahr_to_celsius(float fahr) {
  float celsius = (5.0/9.0) * (fahr - 32);
  return celsius;
}

float celsius_to_fahr(float celsius) {
  float fahr = (9.0/5.0) * celsius + 32;
  return fahr;
}

int main() {
  printf("Celsius: %3.2f\n", fahr_to_celsius(451));
  printf("Fahrenheit: %3.2f\n", celsius_to_fahr(100));
  return 0;
}