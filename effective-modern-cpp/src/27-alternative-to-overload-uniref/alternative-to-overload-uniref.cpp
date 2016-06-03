#include "gtest/gtest.h"


// tag param by std::is_integral and std::true_type


TEST(AvoidOverloadUniversalRefTest, SomeTest) {
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
