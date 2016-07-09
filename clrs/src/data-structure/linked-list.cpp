#include "gtest/gtest.h"

// TODO: linked list: insert, delete,
// TODO: single/double linked list

TEST(LinkedListTest, SomeTest) {
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
