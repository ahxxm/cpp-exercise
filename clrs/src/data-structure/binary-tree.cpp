#include "gtest/gtest.h"

// TODO: build, insert, del, search, min, max, prede/suc cessor

TEST(BinarySearchTreeTest, SomeTest) {
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
