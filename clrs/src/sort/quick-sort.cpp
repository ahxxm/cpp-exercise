#include "gtest/gtest.h"

// TODO: quicksort
// partition(A, p, r) returns 2 index q and t, so that:
// p <= q <=t <= r, A[q..t] are equal


TEST(QuickSortTest, SomeTest) {
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
