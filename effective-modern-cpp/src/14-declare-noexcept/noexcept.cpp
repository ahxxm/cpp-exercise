#include "gtest/gtest.h"

// fail to declare noexcept when it won't emit exception
// is "simply poor interface specification".


// noexcept allow compiler generate better code
// FIXME: with C++11, "the stack is only possibly unwound before
// program execution is terminated"
// C++98
void f(int) throw() {}
// C++11
void f(double) noexcept {}

// conditional noexcept
void v() noexcept(noexcept(f(1)) && noexcept(f(1.0))) {}


TEST(NoexceptTest, SomeTest) {
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
