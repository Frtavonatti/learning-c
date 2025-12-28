#include <stdio.h>
#include <time.h>
#define LEN 10
#define ITERATIONS 100000
/* Exercise 3.1: Our binary search makes two tests inside the loop,
   when one would suffice (at the price of more tests outside).
   Write a version with only one test inside the loop and measure the difference in run-time. */

int binsearch (int x, int v[], int n);
int binsearchopt (int x, int v[], int n);
void test (int (*fn)(int, int [], int), int x, int v[], const char* name);
int arr[LEN] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

void main () {
  printf("TEST 1:\n");
  test(binsearch, 8, arr, "binsearch");
  test(binsearchopt, 8, arr, "binsearchopt");

  printf("TEST 2:\n");
  test(binsearch, 3, arr, "binsearch");
  test(binsearchopt, 3, arr, "binsearchopt");
}

// x is input, v is the array of numbers, n is the length of v
int binsearch(int x, int v[], int n) {
  int low, high, mid;

  low = 0;
  high = n - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    // printf("Initial low: %d, high: %d, mid: %d\n", low, high, mid);
    if (x < v[mid])
      high = mid - 1;
    else if (x > v[mid])
      low = mid + 1;
    else
      return mid;
  }
  return -1;
}

int binsearchopt(int x, int v[], int n) {
  int low = 0, high = n - 1, mid;

  do {
    mid = (low + high) / 2;
    // printf("Optimized low: %d, high: %d, mid: %d\n", low, high, mid);
    if (x < v[mid])
      high = mid - 1;
    else
      low = mid + 1;
  } while (low <= high && v[mid] != x);

  if (v[mid] == x)
    return mid;

  return -1;
}

void test (int (*fn)(int, int [], int), int x, int v[], const char* name) {
  clock_t start, end;
  double cpu_time_used;
  int result;

  start = clock();
  for (int i = 0; i < ITERATIONS * 1000; i++) {
    result = fn(x, v, LEN);
  }
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("%s: %d (time: %f seconds)\n", name, result, cpu_time_used);
}
