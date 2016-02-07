#include "gtest/gtest.h"
#include <vector>
#include <algorithm>


TEST(UniqueTest, SomeTest) {
  std::vector<int> in = {1, 3, 3, 4, 2};
  std::vector<int> out = {1, 3, 4, 2};
  auto end = std::unique(in.begin(), in.end());
  in.erase(end, in.end());
  EXPECT_EQ(in, out);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
