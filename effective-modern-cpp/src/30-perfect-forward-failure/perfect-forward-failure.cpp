#include <vector>
#include <utility>
#include "gtest/gtest.h"

// forward: one function pass its param to another
// goal/perfect: second function receive the same object

// Failures
template<typename... T>
void fwd(T&&... params) {
  f(std::forward<T>(params)...);
}


// Brace initializer
void f(const std::vector<int> &) {}

void brace_fail() {
  // direct: converts to std::vector implicitly
  f({1, 2, 3});

  // forward fail: fwd **deduce** T to be initializer_list
  // fwd({1, 2, 3})
}



TEST(PerfectForwardFailureTest, SomeTest) {
  brace_fail();
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
