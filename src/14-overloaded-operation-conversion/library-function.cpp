#include "gtest/gtest.h"
#include <functional>


TEST(FunctionTest, SomeTest) {
  std::plus<int> jar;
  EXPECT_EQ(jar(1, 2), 3);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
