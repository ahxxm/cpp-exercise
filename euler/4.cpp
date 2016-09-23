#include <algorithm>
#include <string>
#include "gtest/gtest.h"


// Largest palindrome product
// A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
// Find the largest palindrome made from the product of two 3 - digit numbers.


bool is_palindrome_num(const int i) {
  std::string num_string = std::to_string(i);

  // use std reverse?
  std::string reversed(num_string);
  std::reverse(reversed.begin(), reversed.end());

  if (reversed == num_string) {return true;}
  return false;
}

int solve() {
  auto max = 999;
  for (int i = 999; i > 99; --i) {
    for (int j = 999; j > 99; --j) {
      auto k = i * j;
      if (is_palindrome_num(k) && k > max) {
        max = k;
      }
    }
  }
  return max;
}

TEST(PalindromeThreeDigitTest, SomeTest) {
  EXPECT_TRUE(is_palindrome_num(999));
  EXPECT_TRUE(is_palindrome_num(919));
  // EXPECT_EQ(solve(), 906609);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
