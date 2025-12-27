#include <stdio.h>

void print_binary(unsigned int x) {
    int i;
    int bits = sizeof(x) * 8;
    for (i = bits - 1; i >= 0; i--) {
        printf("%d", (x >> i) & 1);
    }
    printf("\n");
}

unsigned getbits(unsigned int x, int p, int n) {
  unsigned bits = (x >> (p+1-n) & ~(~0 << n));
  printf("bin value: %u\n", bits);
  return bits;
}

int main() {
  unsigned int init = 255;
  int num = getbits(init, 4, 3);
  printf("init value: %u\n", init);
  print_binary(init);
  printf("num value: %d\n", num);
  print_binary(num);
  return 0;
}
