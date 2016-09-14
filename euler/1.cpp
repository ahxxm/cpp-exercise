#include "gtest/gtest.h"

// Find the sum of all the multiples of 3 or 5 below 1000.
// https://projecteuler.net/problem=1

// TODO:

TEST(ThreeFiveTest, SomeTest) {
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
