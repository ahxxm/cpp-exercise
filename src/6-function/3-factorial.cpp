#include <iostream>

long factorial(int num) {
  long result = 1;
  for (int i = num; i != 1; --i) {
    result *= (long)i;
  }
  return result;
}

// int main(int argc, char *argv[]) {
void call_factorial(void) {
  long a = factorial(3);
  std::cout << a << std::endl;
}
