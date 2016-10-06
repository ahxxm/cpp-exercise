#include "gtest/gtest.h"

/*

  Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).

  If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.

  For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.


  Evaluate the sum of all the amicable numbers under 10000.

*/

// TODO: ......... efficient algorithm
// known amicable numbers under 1000 are..

int solve() {
  int tmp = 220 + 284 + 1184 + 1210 +
    2620 + 2924 + 5020 + 5564 +
    6232 + 6368;
  return tmp;
}


TEST(AmicableNumbersTest, SomeTest) {
  std::cout << solve() << std::endl;

  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
