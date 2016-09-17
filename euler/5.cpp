#include "gtest/gtest.h"
#include <map>
#include <vector>

// 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
// What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20 ?


// least common multiple = a * b / greatest_common_divisor(a, b)
// gcd(a,b) = gcd(b, a mod b) // O(n/lg(n))
#define N 20
using vi = std::vector<int>;


// TODO: cache and decimal
// for N==20, int is not enough to do multiple first
// for N==24, int is not enough to hold result

int gcd(int a, int b) {
  // make sure a>=b
  if(b > a) {
    auto tmp = b;
    b = a;
    a = tmp;
  }

  // in case b is a's factor
  if(a % b == 0) {return b;}
  return gcd(b, a % b);
}


auto solve(const vi &v) {
  auto result = v[0] * v[1] / gcd(v[0], v[1]);
  for (int j = 2;j < static_cast<int>(v.size()); ++j) {
    result = result / gcd(result, v[j]) * v[j];
  }

  return result;
}


TEST(SmallestMultipleTest, SomeTest) {
  vi k;
  for (int i = 1;i <= N; ++i) {k.emplace_back(i);}
  std::cout << solve(k) << std::endl;
  EXPECT_EQ(static_cast<int>(k.size()), 20);

  EXPECT_EQ(gcd(2, 3), 1);
  EXPECT_EQ(gcd(2, 4), 2);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
