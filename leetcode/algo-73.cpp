#include <set>
#include <vector>
#include "gtest/gtest.h"


/*

  Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

*/


class Solution {

public:

  void setZeroes(std::vector<std::vector<int>> &matrix) {
    uint64_t m = matrix.size();
    if (m == 0) {
      return;
    }

    uint64_t n = matrix[0].size();
    if (n == 0) {
      return;
    }

    // rows/columns to be set
    std::set<int> rows;
    std::set<int> columns;

    for (uint64_t i = 0; i < m; ++i) {
      for (uint64_t j = 0; j < n; ++j) {
        if (matrix[i][j] == 0) {
          rows.insert(i);
          columns.insert(j);
        }
      }
    }

    for (uint64_t i = 0; i < m; ++i) {
      for (uint64_t j = 0; j < n; ++j) {
        if (rows.find(i) != rows.end() || columns.find(j) != columns.end()) {
          matrix[i][j] = 0;
        }
      }
    }

  }

};


TEST(MoreClassExerciseTest, SomeTest) {
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
