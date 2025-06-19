#include <stdio.h>

// - [ ] PENDING REVIEW 
// Exercise 2.1: Write a program to determine the ranges of char, short, int and long variables, both signed and unsigned

#define FIND_UNSIGNED_MAX(type)           \
    do {                                  \
        type x = 0, prev = 0;             \
        while (++x != 0) prev = x;        \
        printf("Max for " #type ": %u\n", prev); \
    } while(0)

int main() {
    FIND_UNSIGNED_MAX(unsigned char);   // 255
    FIND_UNSIGNED_MAX(unsigned short);  // 65535
    FIND_UNSIGNED_MAX(unsigned int);    // 4294967295
    FIND_UNSIGNED_MAX(unsigned long);   // 
    return 0;
}