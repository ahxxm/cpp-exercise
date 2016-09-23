#include <cmath>
#include <set>
#include "gtest/gtest.h"


// 7th triangle number would be 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28.
// Factors:
// 28: 1,2,4,7,14,28

// What is the value of the 1st triangle number to have over 500 divisors?


#define N 500
using ll = long long;


ll factor_count(ll num) {
  std::set<ll> result;

  ll sqr = (ll)sqrt(num) + 1;
  for (ll i = 1; i < sqr; ++i) {
    if (num % i == 0) {
      result.emplace(i);
      result.emplace(num / i);
    }
  }

  return result.size();
}

ll solve() {
  int num = 1;
  int index = 1;
  ll count = 0;
  while (count < N) {
    index += 1;
    num += index;
    count = factor_count(num);
  }
  return num;
}

TEST(DivisorCountTest, SomeTest) {
  EXPECT_EQ(static_cast<int>(factor_count(28)), 6);
  // std::cout << solve() << std::endl;
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
