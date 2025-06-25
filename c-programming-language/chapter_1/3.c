// Exercise 1.3: Add a header before the table 
#include <stdio.h>

int while_fahr_to_celsius() {
  float fahr, celsius;
  float lower, upper, step;
  
  lower = 0;
  upper = 300;
  step = 20;

  printf("Fahr\t Celsius \n");

  fahr = lower;
  while (fahr <= upper) {
    celsius = (5.0/9.0) * (fahr-32.0);
    printf("%3.0f\t %6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }
}

int for_fahr_to_celsius() {
  int fahr;

  printf("Fahr \t Celsius \n");
  for (fahr = 0; fahr <= 300; fahr = fahr + 20)
    printf("%d\t %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}

int main() {
  while_fahr_to_celsius();
  for_fahr_to_celsius();
}

