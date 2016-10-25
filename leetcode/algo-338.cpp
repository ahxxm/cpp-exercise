#include <vector>
#include "gtest/gtest.h"


// Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

class Solution {
public:
    std::vector<int> countBits(int num) {
        std::vector<int> res = std::vector<int>(num+1, 0);
        for (int i = 1; i <= num; i++){
            res[i] = res[i >> 1] + (i & 1);
        }
        return res;
    }
};

TEST(CountingBitsTest, SomeTest) {
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
