#include <stdio.h>

// Exercise 1.4: Celsius to fahrenheit
int main() {
  int celsius;
  printf("Celsius\t Fahr\n");
  for (celsius = 0; celsius <= 300; celsius = celsius + 20) {
    printf("%d\t %6.1f\n", celsius, (9.0/5.0)*celsius+32);
  }
  return 0;
}