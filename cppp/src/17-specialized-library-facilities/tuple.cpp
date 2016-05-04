#include <tuple>
#include "gtest/gtest.h"


TEST(TupleTest, SomeTest) {
  // tuple: "quick and dirty" data structure
  int i = 2;
  float j = 1.1;
  auto k = std::tuple<int, float>(i, j);
  auto item = std::make_tuple(i, j);
  std::cout << std::get<0>(k) << std::endl;

  EXPECT_EQ(std::tuple_size<decltype(k)>::value, 2);
  EXPECT_EQ(std::tuple_size<decltype(item)>::value, 2);

  // 1: 3 int tuple
  std::tuple<int, int, int> three(10, 20, 30);
  EXPECT_EQ(std::tuple_size<decltype(three)>::value, 3);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
