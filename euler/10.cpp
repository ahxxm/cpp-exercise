#include <cmath>
#include "gtest/gtest.h"

// The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

// Find the sum of all the primes below two million.

// copied from 3.cpp
#define N 2000000
using ll = long long;
bool is_prime(ll k) {
  if (k < 2) {return false;}
  if (k == 2) {return true;}
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

// FIXME: 13seconds..
// 142913828922
ll solve() {
  ll result = 0;
  ll i = 1;
  while (i < N) {
    ++i;
    if (is_prime(i)) {result += i;}
  }
  return result;
}


TEST(PrimeSumTest, SomeTest) {
  // std::cout << solve() << std::endl;
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
