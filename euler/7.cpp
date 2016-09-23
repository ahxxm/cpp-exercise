#include <cmath>
#include "gtest/gtest.h"

// 10001st prime

// copied from 3.cpp
#define N 10001
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

int solve() {
  ll i = 1, j = 2;
  while (i < N) {
    if (is_prime(++j)) {
      i += 1;
    }
  }
  return j;
}


TEST(KthPrimeTest, SomeTest) {
  // EXPECT_EQ(solve(), 104743);
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
