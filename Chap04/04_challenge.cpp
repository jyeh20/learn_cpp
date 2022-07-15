#include <cstdio>

void primes(int limit) {
  for (int i = 2; i < limit; i++) {
    if (i % 2 == 0 && i != 2) {
      continue;
    } else if (i % 3 == 0 && i != 3) {
      continue;
    } else if (i % 5 == 0 && i != 5) {
      continue;
    } else if (i % 7 == 0 && i != 7) {
      continue;
    }
    printf("%d ", i);
  }
}

int main() {
  primes(100);
  puts("");
  return 1;
}