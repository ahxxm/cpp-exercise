#include <vector>
#include "static-member.h"
#include "gtest/gtest.h"

double Example::rate;
const std::vector<double> Example::vec = {1.0, 2.0};

TEST(MoreClassExerciseTest, SomeTest) {
  Example data;
  EXPECT_EQ(data.vec[0], 1.0);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
