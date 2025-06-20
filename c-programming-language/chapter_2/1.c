#include <stdio.h>
#include <limits.h>

// Exercise 2.1: Write a program to determine the ranges of char, short, int and long variables, both signed and unsigned
//               by printing appropiate values from standard headers and by direct computation. Harder if you compute them: 
//               determine the ranges of the various floating point types.

#define FIND_UNSIGNED_MAX(type, fmt)      \
    do {                                  \
        type x = 0, prev = 0;             \
        while (++x != 0) prev = x;        \
        printf("Max for " #type ": " fmt "\n", prev); \
    } while(0)
    
#define FIND_SIGNED_MIN(type, fmt)        \
    do {                                  \
        type x = 0, prev = 0;             \
        while (--x < 0) prev = x;         \
        printf("Min for " #type ": " fmt "\t", prev); \
    } while (0)

#define FIND_SIGNED_MAX(type, fmt)        \
    do {                                  \
        type x = 0, prev = 0;             \
        while (++x > 0) prev = x;         \
        printf("Max for " #type ": " fmt "\n", prev); \
    } while(0)

#define FIND_SIGNED_RANGES(type, fmt) \
    do {                            \
        FIND_SIGNED_MIN(type, fmt); \
        FIND_SIGNED_MAX(type, fmt); \
    } while(0)
    
int macro() { 
    printf ("\nUNSIGNED\n");
    FIND_UNSIGNED_MAX(unsigned char, "%u");       // 255
    FIND_UNSIGNED_MAX(unsigned short, "%u");      // 65535
    FIND_UNSIGNED_MAX(unsigned int, "%u");        // 4294967295 (on most systems)
    FIND_UNSIGNED_MAX(unsigned long, "%lu");      // 4294967295 or higher (platform dependent)
    printf("Minimum for unsigned values is always cero\n");
    
    printf ("\nSIGNED\n");
    FIND_SIGNED_RANGES(char, "%20d");             // -128 to 127
    FIND_SIGNED_RANGES(short, "%20d");            // -32768 to 32767
    FIND_SIGNED_RANGES(int, "%20d");              // -2147483648 to 2147483647
    FIND_SIGNED_RANGES(long, "%20ld");            // -2147483648 to 2147483647 or platform dependent
    return 0;
}

int main() {
    macro();

    // Harcoded values for comparison
    printf("\nSIGNED\n");
    printf("Signed char:\t min %20d\t max %20d\n", SCHAR_MIN, SCHAR_MAX);
    printf("Signed short:\t min %20d\t max %20d\n", SHRT_MIN, SHRT_MAX);
    printf("Signed int:\t min %20d\t max %20d\n", INT_MIN, INT_MAX);
    printf("Signed long:\t min %20ld\t max %20ld\n", LONG_MIN, LONG_MAX);

    printf ("\nUNSIGNED\n");
    printf("Unsigned char:\t min %20d\t max %20u\n", 0, UCHAR_MAX);
    printf("Unsigned short:\t min %20d\t max %20u\n", 0, USHRT_MAX);
    printf("Unsigned int:\t min %20d\t max %20u\n", 0, UINT_MAX);
    printf("Unsigned long:\t min %20d\t max %20lu\n", 0, ULONG_MAX);
    return 0;
}