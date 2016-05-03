#include <algorithm>
#include <iostream>
#include <vector>
#include "gtest/gtest.h"


TEST(UniqueTest, SomeTest) {
  std::vector<int> in = {1, 3, 3, 4, 2};
  std::vector<int> out = {1, 3, 4, 2};
  auto end = std::unique(in.begin(), in.end());
  in.erase(end, in.end());
  EXPECT_EQ(in, out);

  // first, end, function
  std::for_each(in.begin(), in.end(), [](const int &i) {std::cout << i << std::endl;});
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
