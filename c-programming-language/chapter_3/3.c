#include <stdio.h>
#include <string.h>

/* Exercise 3-3:
 * Write a function expand(s1, s2) that expands shorthand notations like a-z in the string s1
 * into the equivalent complete list abc...xyz in s2. Allow for letters of either case and digits,
 * and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading or
 * trailing - is taken literally.
 */

void expand(char s1[], char s2[]);
char atoz[4] = "a-z";
char atoz_score[5] = "-a-z";
char atodtoi[6] = "a-d-i";
char atoz_and_0to9[7] = "a-z0-9";
char newarr[100];

void main () {
  expand(atoz, newarr);
  expand(atoz_score, newarr);
  expand(atodtoi, newarr);
  expand(atoz_and_0to9, newarr);
}

void expand(char s1[], char s2[]) {
  memset(s2, 0, sizeof(newarr));
  int i = 0, k = 0;
  int start = 0, end = 0;
  int ccounter = 0, ucounter = 0;
  
  while (s1[i] != '\0') {
    if ((s1[i] >= 'A' && s1[i] <= 'Z') || (s1[i] >= 'a' && s1[i] <= 'z') || (s1[i] >= '0' && s1[i] <= '9')) {
      if (start == 0) {
        start = s1[i++];
      } else {
        end = s1[i++];
      }
      ccounter++;
    } else {
      ucounter++;
      i++;
    }

    if (ccounter == 2 && end > 0 && ucounter > 0) {
      if (start < end) {
        for (int j = start; j <= end; j++) {
          s2[k++] = j;
        }
      }

      while (s1[i] == '-' && s1[i+1] != '\0' &&
            ((end >= 'a' && end <= 'z' && s1[i+1] >= 'a' && s1[i+1] <= 'z') ||
             (end >= 'A' && end <= 'Z' && s1[i+1] >= 'A' && s1[i+1] <= 'Z') ||
             (end >= '0' && end <= '9' && s1[i+1] >= '0' && s1[i+1] <= '9'))) {
        start = end + 1;
        end = s1[i+1];
        for (int j = start; j <= end; j++) {
          s2[k++] = j;
        }
        i += 2;
      }

      start = 0;
      end = 0;
      ccounter = 0;
      ucounter = 0;
    }

    s2[k] = '\0';
  }
  
  printf("cmd: %s\n newarr: %s\n", s1, s2);
}
