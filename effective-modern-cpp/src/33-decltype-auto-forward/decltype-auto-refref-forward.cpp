#include "gtest/gtest.h"

// C++14: Generic lambdas that use auto

template<typename T>
int func(T) {return 42;}


auto f = [](auto x) {return func(x);};

// Usage:
// auto f = [](auto &&... params) {return func(std::forward<decltype(params)>(params)...)};

TEST(DecltypeForwardTest, SomeTest) {
  EXPECT_EQ(f(2), 42);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
