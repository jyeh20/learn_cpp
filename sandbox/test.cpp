#include <cstdio>

int main(int argc, char ** argv) {
  int x = 12;
  const int & y = x;
  int * z = &x;

  printf("x = %d\n", x);
  printf("y = %d\n", y);
  printf("z = %d\n", *z);

  x = 14;
  printf("x = %d\n", x);
  printf("y = %d\n", y);
  printf("z = %d\n", *z);
}