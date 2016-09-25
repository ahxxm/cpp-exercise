#include <cmath>
#include <string>
#include "gtest/gtest.h"
#if defined(__clang__)
# pragma clang diagnostic ignored "-Wunused-variable"
# pragma clang diagnostic ignored "-Wunused-parameter"
#endif
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/lexical_cast.hpp>


/*
  Power digit sum

  2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

  what's sum of 2^1000?
*/

#define N 1000
using ll = boost::multiprecision::int1024_t;

int solve() {
  ll u = 2;
  for(uint64_t i = 1; i < N; ++i) {
    u *= 2;
  }
  std::cout << u << std::endl;

  int result = 0;
  auto str = boost::lexical_cast<std::string> (u);
  for(auto i: str) {
    result += boost::lexical_cast<int>(i);
  }

  return result;
}


TEST(PowerDigitSumTest, SomeTest) {
  // 1366
  // std::cout << solve() << std::endl;
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
