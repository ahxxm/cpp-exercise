#include "gtest/gtest.h"

TEST(JavaTest, TwoPlusTwoEqualsFour) {
  EXPECT_EQ(2 + 2, 4);
}


int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
