#include "gtest/gtest.h"

// forward: one function pass its param to another
// goal/perfect: second function receive the same object



TEST(PerfectForwardFailureTest, SomeTest) {
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
