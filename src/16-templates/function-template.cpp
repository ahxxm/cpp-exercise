#include "gtest/gtest.h"


template <typename T>
int compare(const T &v1, const T &v2) {
  if (v1 < v2) {
    return -1;
  };

  if (v1 > v2) {
    return 1;
  };

  return 0;
}



TEST(FunctionTemplateTest, SomeTest) {
  int f = compare<int>(1, 2);
  EXPECT_EQ(f, -1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
