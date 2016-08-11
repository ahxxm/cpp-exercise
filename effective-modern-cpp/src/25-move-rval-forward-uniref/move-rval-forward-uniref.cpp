#include <iostream>
#include "gtest/gtest.h"

// apply move/forward on the last time used
// move ctor more efficient

// RVO: return value optimization // FIXME:

struct C {
  C() = default;
  C(const C&) {std::cout << "copied!" << std::endl;}
};

auto f() {
  return C();
}

int main(void) {
  std::cout << "start" << std::endl;
  auto obj = f();

  // copy may be made 0 1 2 times, depends on compiler
  std::cout << &obj << std::endl;

  return 0;
}
