#include <stdio.h>

// Exercise 13: Write program to print a histogram of the lenghts of words in its input (horizontal and vertical). 
int main () {
  int lengtharr[10];
  int c, wlength, otherlength;

  wlength = otherlength = 0;

  for (int i = 0; i < 10; ++i) {
    lengtharr[i] = 0;
  }

  // Use ctrl + D (linux) / ctrl + Z (windows) to end the execution of the program (EOF)
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      if (lengtharr[wlength] >= 0)
        ++lengtharr[wlength];
      else
        ++otherlength;
      wlength = 0;
    } else {
      ++wlength;
    }
  }

  printf("ARRAY: [");
  for (int i = 0; i < 10; ++i)
    if(i == 9)
      printf("%d]\n\n", lengtharr[i]);
    else
      printf("%d, ", lengtharr[i]);

  printf("Length histogram\n");
  for (int i = 0; i < 10; ++i) {
    printf("%d: ", i);
    for (int j = lengtharr[i]; j > 0; --j)
      printf("#");
    printf("\n");
  }

  printf("Otherlength: %d\n", otherlength);
  return 0;
}