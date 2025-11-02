#include <stdio.h>
#include <string.h>
#define MAXLINES 1000
#define TABS 8

/* Exercise 1.21: Write a program entab that replaces strings of blanks by the minimum number of tabs and blanks
                  to achieve the the same spacing. Use the same tab stops as for detab.
                  When either a tab or a single blank would suffice to reach a tab stop, which should be given preference?
*/

void entab (const char input[], char str[], int limit);

/* Test input and expected output strings */
/* For visual representation: spaces as '.' and tabs as '-' */
char test_input1[]  = ".foo:...bar;......#comment";
char test_output1[] = ".foo:-bar;-..#comment";

char test_input2[]  = ".......-foo:.....bar;......#comment";
char test_output2[] = "-foo:-.bar;-...#comment";

struct test_case {
   char *input;
   char *expected;
};

struct test_case test_suite[] = {
  { test_input1, test_output1 },
  { test_input2, test_output2 }
};

int main () {
  char arr[MAXLINES];
  int num_tests = sizeof(test_suite) / sizeof(test_suite[0]);
  for (int t = 0; t < num_tests; t++) {
   entab(test_suite[t].input, arr, MAXLINES);
   printf("Test %d:\n", t + 1);
   printf("Input:  %s\n", test_suite[t].input);
   printf("Result: %s\n", arr);
   printf("Expect: %s\n", test_suite[t].expected);
   printf("Pass:   %s\n\n", (strcmp(arr, test_suite[t].expected) == 0) ? "YES" : "NO");
  }
  return 0;
}

void flush_spaces(char str[], int *i, int *space_count) {
  while (*space_count > 0) {
    str[(*i)++] = '.';
    (*space_count)--;
  }
}

void entab (const char input[], char str[], int lim) {
  int i = 0, c;
  int space_count = 0;
  int col = 0; // index for input string
  
  // while ((c = getchar()) != EOF)
  while ((c = input[col++]) != '\0' && i < MAXLINES) {
    int col_offset = col % TABS;

    if (c == '.') {
      space_count++;
      if (space_count == TABS || col_offset == 0) {
        str[i++] = '-';
        space_count = 0;
      }
    }
    else if (c == '-') {
      if (col_offset == 0) {
        space_count = 0;
        str[i++] = '-';
      } else {
        flush_spaces(str, &i, &space_count);
        str[i++] = '-';
      }
    }
    else {
      flush_spaces(str, &i, &space_count);
      str[i++] = c;
    }
  }

  str[i] = '\0';
}