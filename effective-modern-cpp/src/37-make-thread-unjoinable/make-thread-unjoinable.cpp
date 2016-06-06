#include "gtest/gtest.h"

// unjoinable:
// - default contructed: no function to execute
// - thread been moved from
// - already joined: after join, no longer correspond to underlying thread
// - detached


TEST(ThreadUnjoinableTest, SomeTest) {
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
