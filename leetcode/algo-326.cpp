#include "gtest/gtest.h"

class Solution {
public:
  bool isPowerOfThree(int n) {
    // because it's an int
    return n > 0 && (1162261467 % n == 0);
  }
};


TEST(PoTTest, SomeTest) {
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
