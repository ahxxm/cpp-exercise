#include "gtest/gtest.h"

// TODO: search, insert, del, min, max, predecessor/successor(ordered set),

TEST(SetTest, SomeTest) {
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
