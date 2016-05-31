#include "gtest/gtest.h"


// unique_ptr should be first considered
// almost as fast as raw pointer


TEST(UniquePtrTest, SomeTest) {
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
