#include "gtest/gtest.h"

// Find the sum of all the multiples of 3 or 5 below 1000.
// https://projecteuler.net/problem=1

#define N 999
// "below"

int sum(int n, int d) {
  // N and divider
  auto count = n / d;
  return count * (d + count * d) / 2;
}

int euler1() {
  return sum(N, 3) + sum(N, 5) - sum(N, 15);
}

TEST(ThreeFiveTest, SomeTest) {
  EXPECT_EQ(sum(10, 3), 18);
  EXPECT_EQ(sum(14, 3), 30);
  EXPECT_EQ(euler1(), 233168);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
