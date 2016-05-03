#include <iostream>

int main(void) {

  // const int
  const int i = 42;

  // int
  auto j = i;

  // const int reference
  const auto &k = i;

  // const int*
  auto *p = &i;

  std::cout << j << " " << *p << " " << k << std::endl;
}
