#include <stdio.h>

/* Exercise 3-2:
 * Write a function escape(s, t) that converts characters like newline and tab
 * into visible escape sequences like \n and \t as it copies the string t to s.
 * Use a switch statement. Write a function for the inverse operation as well,
 * converting escape sequences into the real characters.
 */

char text[100] = "\b H e l l o \t W o r l d \n";
char newarr[100];
char unescaped[100];

void scape(char s[], char t[]);
void scape_to_str(char s[], char t[]);

void main () {
  printf("initialarr: %s\n", text);
  scape(newarr, text);
  printf("newarr: %s\n", newarr);
  scape_to_str(unescaped, newarr);
  printf("unescaped: %s\n", unescaped);
}

// s: destination | t: original
void scape(char s[], char t[]) {
  int j = 0;
  for (int i = 0; t[i] != '\0'; i++) {
    switch(t[i]) {
      case '\t':
        s[j++] = '\\';
        s[j++] = 't';
        break;
      case '\n':
        s[j++] = '\\';
        s[j++] = 'n';
        break;
      case '\b':
        s[j++] = '\\';
        s[j++] = 'b';
        break;
      default:
        s[j++] = t[i];
        break;
      break;
    }
  }
  s[j++] = '\0';
}

// s: destination | t: original
void scape_to_str(char s[], char t[]) {
  int j = 0;
  for (int i = 0; t[i] != '\0'; i++) {
    if (t[i] == '\\') {
      i++;
      switch(t[i]) {
        case 't':
          s[j++] = '\t';
          break;
        case 'n':
          s[j++] = '\n';
          break;
        // case 'b':
        //   s[j++] = '\b';
        //   break;
        default:
          printf("error: case %c not covered\n", t[i]);
          break;
      }
    } else {
      s[j++] = t[i];
    }
  }
  s[j++] = '\0';
}
