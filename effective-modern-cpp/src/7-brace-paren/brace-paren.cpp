#include <utility>
#include <iostream>
#include <vector>
#include "gtest/gtest.h"


// "Uniform initialization", braced because can be used everywhere
// uncopyable object's can't use = initialization
// FIXME: like std::atomic but what's that

void prevent_implicit_conversion() {
  double a = 0.0, b = 0.0, c = 0.0;
  // int sum {a + b + c}; //warning
  int sum(a + b + c); // this works..
  int sum2 = a + b + c; // also this
  std::cout << &sum << &sum2 << std::endl;
}


class Widget {
public:
  Widget() = default;
  Widget(int, bool) {};
  Widget(int, double) {};

  // bool will cause narrow conversion(warning)
  // string will let other 2 ctor work because
  // no conversion
  Widget(std::initializer_list<long double>) {
    std::cout << "WAT" << std::endl;
    value = 42;
  };
  int value = 0;

};

void ctor() {
  // Anything that can be parsed as a declaration must be
  // interpreted as one

  // warned by clang, -Wvexing-parse
  // Widget w1 (); // this is a function, "most vexing parse"

  Widget w2 {}; // this constructs w2 with no args
  std::cout << &w2 << std::endl;

}

void drawback() {
  // as mentionedin Item 2, constructed as initializer list
  auto a = {1, 2, 3};
  std::cout << a.size() << std::endl;
}



TEST(BraceParenTest, SomeTest) {
  prevent_implicit_conversion();
  ctor();
  drawback();

  // Drawback 2, args converted to initializer_list and pass
  // to "matched ctor"
  // true and 5.0 are converted to long double
  Widget W1 {10, true};
  Widget W2 {10, 5.0};
  EXPECT_EQ(W1.value, 42);
  EXPECT_EQ(W2.value, 42);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
