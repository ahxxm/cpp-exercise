#include "gtest/gtest.h"

// TODO: ctor, insert, insertfix, left/right rotate, del node, delfix,
// successor/predesessor, search, min/max, black-height(node)
// TODO: display?
// TODO: chap problems and exercises


TEST(RBTreeTest, SomeTest) {
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
