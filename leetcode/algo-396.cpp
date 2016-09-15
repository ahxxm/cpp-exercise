#include "gtest/gtest.h"
#include <vector>
/*
  Given an array of integers A and let n to be its length.

  Assume Bk to be an array obtained by rotating the array A k positions clock-wise, we define a "rotation function" F on A as follow:

  F(k) = 0 * Bk[0] + 1 * Bk[1] + ... + (n-1) * Bk[n-1].

  Calculate the maximum value of F(0), F(1), ..., F(n-1).

  Note:
  n is guaranteed to be less than 10^5.

  Example:

  A = [4, 3, 2, 6]

  F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
  F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
  F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
  F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26

  So the maximum value of F(0), F(1), F(2), F(3) is F(3) = 26.
 */

#define DEBUG true
#ifdef DEBUG
#include <cassert>
#endif

class Solution {
public:

  int calculate(const std::vector<int> &v, int r, const int s) {
    // offset: rotate count
    // s: vector size
#ifdef DEBUG
    assert(s > r);
#endif

    int result = 0;

    // for example rotate 1 on [4,3,2,6]
    // part1: origin weight of 4 3 2 each added 1
    // from [0,1,2] to [1,2,3]
    for (int i = 0; i < s - r; ++i) {
      auto base = i + r;
      result += base * v[i];
    }
    // part2: 6
    int k = 0;
    for (int j = s - r;j < s; ++j) {
      result += v[j] * k;
      k += 1;
    }

    return result;
  }


  int maxRotateFunction(std::vector<int> &A) {
    int n = A.size();
    if(n == 0) {return 0;}

    int max = calculate(A, 0, n);
    for (int i = 0; i < n; ++i) {
      auto sum = calculate(A, i, n);
      if(sum > max) {
        max = sum;
      }

    }
    return max;
  }
};




TEST(RotateFunctionTest, SomeTest) {
  auto s = Solution();
  std::vector<int> aa {4, 3, 2, 6};
  EXPECT_EQ(s.maxRotateFunction(aa), 26);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
