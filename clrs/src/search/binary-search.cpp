#include <vector>
#include "gtest/gtest.h"

using TT = std::vector<int>;

// 2.3-5
// binary search...
template <typename T>
int bs(const std::vector<T>&vec, const T &num) {
  // vec should be a sorted container
  // which supports O(1) subscript access
  int low = 0, high = vec.size(), not_found = -1;
  auto mid = low + (high - low) / 2;

  if (vec[0] == num) {
    return 0;
  }

  if (vec[high - 1] == num) {
    return high;
  }

  while (mid != low && mid != high) {
    auto val = vec.at(mid);
    if (val == num) {
      return mid;
    } else {
      // left side
      if (val > num) {
        high = mid;
        mid = (low + mid) / 2;
      } else {
        low = mid;
        mid = mid + (high - mid) / 2;
      }
    }
  }

  return not_found;
}


TEST(BSTest, SomeTest) {
  TT a = {1, 2, 3, 5, 6, 7, 9};
  TT b = {1, 2, 3, 5, 6, 7};
  EXPECT_EQ(bs(a, 1), 0);
  EXPECT_EQ(bs(a, 2), 1);
  EXPECT_EQ(bs(a, 4), -1);

  EXPECT_EQ(bs(b, 1), 0);
  EXPECT_EQ(bs(b, 3), 2);
  EXPECT_EQ(bs(b, 20), -1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
