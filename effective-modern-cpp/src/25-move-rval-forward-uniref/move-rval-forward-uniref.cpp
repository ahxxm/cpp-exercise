#include "gtest/gtest.h"

// apply move/forward on the last time used
// move ctor more efficient

// RVO: return value optimization // FIXME:


TEST(MoveForwardTest, SomeTest) {
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
