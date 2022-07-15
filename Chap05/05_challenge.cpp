#include <cstdio>

int non_recurse_factorial(const int num) {
  int factorial = 0;
  for (int i = 0; i <= num; i++) {
    int & factorial_ref = factorial;
    if (i < 2) {
      factorial_ref = 1;
    } else {
      factorial_ref = i * factorial;
    }
  }
  return factorial;
}

int main() {
  printf("Factorial of %d is %d\n", 5, non_recurse_factorial(5));
}