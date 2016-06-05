#include "gtest/gtest.h"


// reason: lambdas are more readable
// bind param will be evaluated and stored in bind object,
// so a nested function might be needed.


TEST(PreferLambdaTest, SomeTest) {
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
