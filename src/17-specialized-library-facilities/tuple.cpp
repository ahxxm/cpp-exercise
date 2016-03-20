#include "gtest/gtest.h"
#include <tuple>


TEST(TupleTest, SomeTest) {
  // tuple: "quick and dirty" data structure
  int i = 2;
  float j = 1.1;
  auto k = std::tuple<int, float>(i, j);
  std::cout << std::get<0>(k) << std::endl;

  EXPECT_EQ(std::tuple_size<decltype(k)>::value, 2);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
