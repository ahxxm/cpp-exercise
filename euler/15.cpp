#include "gtest/gtest.h"

// Starting in the top left corner of a 2×2 grid,
// and only being able to move to the right and down,
// there are exactly 6 routes to the bottom right corner.

// How many such routes are there through a 20×20 grid?


using ll = uint64_t;

ll solve(ll num) {
  ll result = 1;
  for (ll i = 0; i < num; ++i) {
    result *= (2 * num) - i;
    result /= i + 1;
  }
  return result;
}

TEST(LatticePathTest, SomeTest) {
  std::cout << solve(20) << std::endl;
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
