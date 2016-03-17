#include "gtest/gtest.h"
#include <iostream>
#include <ostream>


template <typename T, typename... Args>
void foo(const T &, const Args&... rest) {
  // number of type params
  std::cout << sizeof...(Args) << std::endl;

  // number of function params
  std::cout << sizeof...(rest) << std::endl;
};


template <typename T>
std::ostream &print(std::ostream &os, const T &t) {
  return os << t;
};

template <typename T, typename... Args>
std::ostream &print(std::ostream &os, const T &t, const Args&... rest) {
  // first arg
  os << t << ", ";

  // recursively rest: first of rest is bounded to t, others to rest
  // ... until match print above
  return print(os, rest...);
};


TEST(ArgPackTest, SomeTest) {
  foo(1, 2, 3, "jar");
  print(std::cout, 1, 2, 3, "42");
  std::cout << std::endl;

}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
