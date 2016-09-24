#include <vector>
#include "gtest/gtest.h"

using TT = std::vector<int>;

TT selectSort(TT ve) {
  int min_index, tmp;
  for (uint64_t i = 0; i < ve.size() - 1; ++i) {
    min_index = i;
    for (uint64_t j = i + 1; j < ve.size(); ++j) {
      // find smallest
      if (ve[j] < ve[i]) {
        min_index = j;
      }

      // exchange with vector[i]
      if (static_cast<unsigned long>(min_index) != i) {
        tmp = ve[i];
        ve[i] = ve[min_index];
        ve[min_index] = tmp;
      }
    }

  }
  return ve;
};



TEST(SelectSortTest, SomeTest) {
  TT a = {1, 4, 3, 2};
  TT b = {1, 2, 3, 4};
  EXPECT_EQ(selectSort(a), b);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
