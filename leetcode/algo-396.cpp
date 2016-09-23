#include <vector>
#include "gtest/gtest.h"


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


class Solution {
public:
  int maxRotateFunction(std::vector<int> &A) {
    int n = A.size();
    if (n == 0) {return 0;}

    int sum = 0, tmp = 0;
    for (int i = 0; i < n; ++i) {
      sum += A[i];
      tmp += i * A[i];
    }

    int result = tmp;
    for (int i = n - 1; i >= 0; --i) {
      tmp += sum - n * A[i];
      if (tmp > result) {result = tmp;};
    }
    return result;
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
