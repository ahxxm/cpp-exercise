#include "gtest/gtest.h"
#include <iostream>


template <typename T, typename... Args>
void foo(const T &, const Args&... rest) {
  // number of type params
  std::cout << sizeof...(Args) << std::endl;

  // number of function params
  std::cout << sizeof...(rest) << std::endl;
};


TEST(ArgPackTest, SomeTest) {
  foo(1, 2, 3, "jar");
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
