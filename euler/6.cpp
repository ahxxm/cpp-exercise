#include "gtest/gtest.h"

// (1+2+3...+100)^2-(1^2+2^2+....100^2)
#define N 100

using ll = int64_t;
ll solve() {
  ll sum_square = 0;
  ll sum = 0;
  for (ll i = 1; i <= N; ++i) {
    sum += i;
    sum_square += i * i;
  }

  ll square_sum = sum * sum;
  return square_sum - sum_square;

}

TEST(SumSquareDiffTest, SomeTest) {
  EXPECT_EQ(solve(), 25164150);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
