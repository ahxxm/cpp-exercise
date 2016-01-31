#include "gtest/gtest.h"



TEST(ContainerTest, SomeTest) {
  EXPECT_EQ(1, 1);
  // 9.1 vector, deque, or a (linked) list?
  // (a): list then convert, or vector then sort,
  // or associative containers <= FIXME
  // (b): deque
  // (c): vector then sort
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
