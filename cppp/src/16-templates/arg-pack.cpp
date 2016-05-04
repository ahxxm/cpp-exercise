#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include "gtest/gtest.h"


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



// unpack
template <typename T>
std::string debug_rep(const T &t) {
  std::ostringstream ret;
  ret << t;
  return ret.str();
}

template <typename... Args>
std::ostream &errorMsg(std::ostream &os, const Args&... rest) {
  // call debug_rep on each arg, equals:
  // print(os, debug_rep(rest1), debug_rep(rest2), ... debug_rep(restN));
  return print(os, debug_rep(rest)...);
}

TEST(ArgPackTest, SomeTest) {
  foo(1, 2, 3, "jar");
  print(std::cout, 1, 2, 3, "42");
  std::cout << std::endl;

  std::string a = "aa";
  std::string b = "bb";
  errorMsg(std::cout, a, b);
  std::cout << std::endl;
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
