#include "gtest/gtest.h"

// fail to declare noexcept when it won't emit exception
// is "simply poor interface specification".


// noexcept allow compiler generate better code
// C++98
void f(int) throw() {};
// C++11
void f(double) noexcept {};



TEST(NoexceptTest, SomeTest) {
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
