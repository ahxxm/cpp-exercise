#include "gtest/gtest.h"
#include <numeric>
#include <vector>
#include <string>
#include <algorithm>


TEST(AlgoMoreTest, SomeTest) {
  // 3: accumulate
  std::vector<int> jar = {1, 2, 4, 3};
  int sum = std::accumulate(jar.cbegin(), jar.cend(), 0);
  EXPECT_EQ(sum, 10);

  std::sort(jar.begin(), jar.end());
  EXPECT_EQ(jar[3], 4);

  // the third arg is return type and start point of accumulation
  std::vector<std::string> strong = {"a", "b", "c"};
  std::string s = std::accumulate(strong.cbegin(), strong.cend(), std::string(""));
  EXPECT_EQ(s, "abc");

  // in-place replace
  std::replace(strong.begin(), strong.end(), "c", "d");
  EXPECT_EQ(strong[2], "d");
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
