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


TEST(BraceParenTest, SomeTest) {
  prevent_implicit_conversion();
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
