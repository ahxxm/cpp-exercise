#include "gtest/gtest.h"

// std::async: request function be run according to std::async **launch policy**
// 2 policies:
// std::launch::async - must run asynchronously
// std::launch::deferred - may run when get() or wait() called on future object

// default policy is mixed, so no way to predict behavior.

TEST(LaunchAsyncTest, SomeTest) {
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
