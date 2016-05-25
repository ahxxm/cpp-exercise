#include "gtest/gtest.h"

// with 1 exception, auto deduction is template deduction.
// "auto plays the role of **T** in the template"


int auto1() {
  auto x = 27;
  // const auto cx = x; // const int
  auto &rx = x; // int &
  rx = 233;
  return x;
}

TEST(MoreClassExerciseTest, SomeTest) {
  EXPECT_EQ(auto1(), 233);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
