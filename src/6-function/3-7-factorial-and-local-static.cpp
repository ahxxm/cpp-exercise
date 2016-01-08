#include <iostream>

// exercise 3
long factorial(int num) {
  long result = 1;
  for (int i = num; i != 1; --i) {
    result *= (long)i;
  }
  return result;
}

size_t count_calls() {
  // declaration is only went through for the first
  // time...
  static size_t ctr = 0;
  // exercise 7: change this to ctr++
  // so that return 0 at first, then increment by 1 on call
  return ++ctr;
}

// int main(int argc, char *argv[]) {
void call_factorial(void) {
  long a = factorial(3);
  std::cout << a << std::endl;

  // will print 1 to 10 ....
  for (size_t j = 0; j != 10; ++j) {
    std::cout << count_calls() << std::endl;
  }

}
