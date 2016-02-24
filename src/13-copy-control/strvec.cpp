#include "gtest/gtest.h"
#include <vector>
#include <string>


class StrVec {

};

TEST(StrVecTest, SomeTest) {
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
