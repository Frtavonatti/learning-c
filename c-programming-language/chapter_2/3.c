#include <stdio.h>

/* Exercise 2-3. Write a function htoi(s), which converts a string of hexadecimal digits
        (including an optional 0x or 0X) into its equivalent integer value. 
        The allowable digits are 0 through 9, a through f, and A through F. 
*/

int htoi (const char input[]);
int convert(int c);
int strlength(const char s[]);

char test_input1[]  = "0x1A3f";
int test_output1 = 6719;

char test_input2[]  = "FF";
int test_output2 = 255;

char test_input3[]  = "0Xabc";
int test_output3 = 2748;

struct test_case {
   char *input;
   int *expected;
};

struct test_case test_suite[] = {
  { test_input1, &test_output1 },
  { test_input2, &test_output2 },
  { test_input3, &test_output3 }
};

int main() {
  int num_tests = sizeof(test_suite) / sizeof(test_suite[0]);

  for (int t = 0; t < num_tests; t++) {
    int result = htoi(test_suite[t].input);
    printf("Test %d:\n", t + 1);
    printf("Input:  %s\n", test_suite[t].input);
    printf("Result: %d\n", result);
    printf("Expect: %d\n", *test_suite[t].expected); // Dereference with *
    printf("Pass:   %s\n\n", (result == *test_suite[t].expected) ? "YES" : "NO");
  }
  
  return 0;
}

// TO-DO: Current solution has O(n2) complexity improve to O(n)
int htoi (const char input[]) {
  int result = 0;
  int len = strlength(input);
  
  for (int i = len - 1; i >= 0; i--) {
    int digit = convert(input[i]);
    int power = 1;
        
    for (int j = 0; j < (len-1 - i); j++) // reversed countdown
      power *= 16;
        
    result += digit * power;

    /* printf("i is: %d\n", i);
    printf("r is: %d\n", result);
    printf("p is: %d\n", power);
    printf("char is: %c\n", input[i]);
    printf("digit is: %d\n", digit);
    printf("---\n"); */
  }

  return result;
}

// Auxiliary functions for string length and hexadecimal digit conversion
int strlength (const char input[]) {
  int i;
  for (i = 0; input[i] != '\0'; i++) {}
  return i;
}

int convert (int c) {
  if (c >= '0' && c <= '9')
    return c - '0';
  if (c >= 'A' && c <= 'F') 
    return c - 'A' + 10;
  if (c >= 'a' && c <= 'f') 
    return c - 'a' + 10;
  return 0;
}