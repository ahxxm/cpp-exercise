#include "gtest/gtest.h"
#include <math.h>
// The prime factors of 13195 are 5, 7, 13 and 29.
// What is the largest prime factor of the number 600851475143 ?

using ll = long long;


bool is_prime(ll k) {
  if(k < 2) {return false;}
  if(k == 2) {return true;}
  ll sq = sqrt(k);
  ll tmp;
  while (sq > 1) {
    tmp = k / sq;
    if (tmp * sq == k) {
      return false;
    }
    --sq;
  }
  return true;
}

ll solve() {
  ll k = 600851475143;
  ll i = 2;
  while(i < k) {
    ll d = k / i;
    if (d * i == k && is_prime(d)) {return d;}
    ++i;
  }
  return i;
}

TEST(LargestPrimeFactorTest, SomeTest) {
  EXPECT_EQ(1, 1);
  // FIXME: takes too long
  // std::cout << solve() << std::endl;
  EXPECT_FALSE(is_prime(4));
  EXPECT_TRUE(is_prime(3));
  EXPECT_TRUE(is_prime(2));
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
