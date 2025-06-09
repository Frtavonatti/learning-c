#include <stdio.h>

// Exercise 1.1 -1.2
int put() {
  puts("Hello world");
}

// Escape sequences: \n = newline || \t = tab || \b = backspace || \ = double quote || \\ backslash itself  
int main() {
  put();
  printf("Hello world \n");
}