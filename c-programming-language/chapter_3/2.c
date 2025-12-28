#include <stdio.h>

/* Exercise 3-2:
 * Write a function escape(s, t) that converts characters like newline and tab
 * into visible escape sequences like \n and \t as it copies the string t to s.
 * Use a switch statement. Write a function for the inverse operation as well,
 * converting escape sequences into the real characters.
 */

char text[100] = "\b H e l l o \t W o r l d \n";
char newarr[100];

void scape(char s[], char t[]);

void main () {
  printf("initialarr: %s\n", text);
  scape(newarr, text);
  printf("newarr: %s\n", newarr);
}

// s: destination | t: original
void scape(char s[], char t[]) {
  int j = 0;
  for (int i = 0; t[i] != '\0'; i++) {
    switch(t[i]) {
      case '\t':
        s[j++] = '\\';
        s[j++] = 't';
        s[j++] = ' ';
        break;
      case '\n':
        s[j++] = '\\';
        s[j++] = 'n';
        s[j++] = ' ';
        break;
      case '\b':
        s[j++] = '\\';
        s[j++] = 'b';
        s[j++] = ' ';
        break;
      default:
        s[j++] = t[i];
        break;
      break;
    }
  }
}
