#include "gtest/gtest.h"

// TODO:
// stack: push, pop, top
// queue: enqueue, dequeue


TEST(StackQueueTest, SomeTest) {
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
