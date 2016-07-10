#include "gtest/gtest.h"

// TODO: ctor, push, pop, sort, merge

TEST(HeapTest, SomeTest) {
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
