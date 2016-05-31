#include "gtest/gtest.h"


// constexpr is interface of object/function
// FIXME: re-read this chapter..


// constexpr (conceptually) means value is known during compilation
// FIXME: (technically it's during `translation`)


TEST(ConstexprTest, SomeTest) {
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
