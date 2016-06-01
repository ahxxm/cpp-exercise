#include "gtest/gtest.h"


// all shared_ptr points to object collaborate to
// ensure proper destruction.(like ref count?)


TEST(SharedPtrTest, SomeTest) {
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
