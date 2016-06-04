#include "gtest/gtest.h"


// compilers are **required** to use move

// Reason to assume move not available:
// some types does not have cheap move: std::array for example
// unstable api could result in: no move operation


TEST(NoMoveTest, SomeTest) {
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
