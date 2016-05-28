#include <iostream>
#include <vector>
#include "gtest/gtest.h"


// "Uniform initialization", braced because can be used everywhere
// uncopyable object's can't use = initialization
// FIXME: like std::atomic but what's that

void prevent_implicit_conversion() {
  double a, b, c;
  // int sum {a + b + c}; //warning
  int sum(a + b + c); // this works..
  int sum2 = a + b + c; // also this
  std::cout << &sum << &sum2 << std::endl;
}


class Widget {};

void ctor() {
  // Anything that can be parsed as a declaration must be
  // interpreted as one
  Widget w1 (); // this is a function, "most vexing parse"
  Widget w2 {}; // this constructs w2 with no args
  std::cout << &w2 << std::endl;

}


TEST(BraceParenTest, SomeTest) {
  prevent_implicit_conversion();
  ctor();
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
