#include "gtest/gtest.h"

// TODO:
// heap algo
// heap operation: maxify, build, remove, get min/max,
// sort


TEST(HeapTest, SomeTest) {
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
