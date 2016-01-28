#include "gtest/gtest.h"
#include "static-member.h"
#include <vector>

// 58: fix errors and explain why
// FIXME: not sure what static member can do..
double Example::rate;
// std::vector<double> Example::vec;

TEST(MoreClassExerciseTest, SomeTest) {
  Example data;
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
