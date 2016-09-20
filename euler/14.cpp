#include "gtest/gtest.h"

/*

The following iterative sequence is defined for the set of positive
integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following
sequence:

13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1


Which starting number, under one million, produces the longest chain?
NOTE: Once the chain starts the terms are allowed to go above one
million.
*/

#define N 4000000

int solve() {
  int i = 8;
  while(i < N) {
    std::cout << i << std::endl;

    if(i % 3 == 1) {
      i = (i - 1) / 3;
    } else {
      i *= 2;
    }
    if(i > 1000000) {
      std::cout << i << std::endl;
    }
  }
  return i;
}

TEST(LongestCollatzTest, SomeTest) {
  std::cout << solve() << std::endl;

  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
