#include <string>
#include "gtest/gtest.h"


// aggregate class:
// - no contructor
// - no in-class initializer
// - no base class nor virtual function
struct Data {
  int ival;
  std::string s;
};


TEST(MoreClassExerciseTest, SomeTest) {
  int j = 233;
  // should follow order in definition
  Data data1 = {j, "Anna"};
  EXPECT_EQ(data1.ival, j);

  // missing field will be default initialized
  // but there will be a warning in -Wextra
  // Data data2 = {j};
  // EXPECT_EQ(data2.s, "");
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
