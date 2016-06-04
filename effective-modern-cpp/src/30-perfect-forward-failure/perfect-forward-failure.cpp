#include <vector>
#include <utility>
#include "gtest/gtest.h"

// forward: one function pass its param to another
// goal/perfect: second function receive the same object

// Failures



// Brace initializer
void f(const std::vector<int> &) {}

template<typename... Ts>
void fwd(Ts&&... params){
  f(std::forward<Ts>(params)...);
}

void brace_fail() {
  // direct: converts to std::vector implicitly
  f({1, 2, 3});

  // fwd({1, 2, 3});
  // forward fail: {} is not declared as initializer_list
  // , compiler is forbidden to deduced it.

  // fix:
  auto il = {1, 2, 3};
  fwd(il);
}

// 0/NULL as nullptr



TEST(PerfectForwardFailureTest, SomeTest) {
  brace_fail();
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
