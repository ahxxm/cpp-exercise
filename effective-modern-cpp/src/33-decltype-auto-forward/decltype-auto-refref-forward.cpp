#include "gtest/gtest.h"

// C++14: Generic lambdas that use auto

template<typename T>
void func(T) {}


// auto f = [](auto x) {return func(x);};

// Usage:
// auto f = [](auto &&... params) {return func(std::forward<decltype(params)>(params)...)};

TEST(DecltypeForwardTest, SomeTest) {
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
