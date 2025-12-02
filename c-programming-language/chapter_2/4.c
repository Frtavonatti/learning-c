#include <stdio.h>
#include <string.h>

/* Exercise 2.4: Write an alternative version of squeeze(s1, s2) that deletes
          each character in s1 that matches any character in the string s2. */

void squeeze (char s1[], const char s2[]);

struct test_case {
    char input[100];
    const char *s2;
    const char *expected;
};

struct test_case test_suite[] = {
    { "hello world", "ole", "h wrd" },
    { "abcdef", "bdf", "ace" },
    { "123456789", "13579", "2468" } ,
    { "test", "xyz", "test" },
    { "banana", "an", "b" }
};

int main () {
    int num_tests = sizeof(test_suite) / sizeof(test_suite[0]);
    for (int t = 0; t < num_tests; t++) {
        char s1[100];
        strcpy(s1, test_suite[t].input);
        squeeze(s1, test_suite[t].s2);
        printf("Test %d:\n", t + 1);
        printf("Input:    \"%s\"  S2: \"%s\"\n", test_suite[t].input, test_suite[t].s2);
        printf("Result:   \"%s\"\n", s1);
        printf("Expected: \"%s\"\n", test_suite[t].expected);
        printf("Pass:     %s\n\n", strcmp(s1, test_suite[t].expected) == 0 ? "YES" : "NO");
    }
    return 0;
}

void squeeze (char s1[], const char s2[]) {
  int k = 0;
  for (int i = 0; i < strlen(s1); i++) {
    int found = 0;
    for (int j = 0; j < strlen(s2); j++) {
      if (s1[i] == s2[j]) {
        found = 1;
        break;
      }
    }
    if (!found) {
      s1[k++] = s1[i];
    }
  }
  
  s1[k] = '\0';
}
