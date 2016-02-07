#include "gtest/gtest.h"
#include <numeric>
#include <vector>
#include <string>


TEST(AlgoMoreTest, SomeTest) {
  // 3: accumulate
  std::vector<int> jar = {1, 2, 3, 4};
  int sum = std::accumulate(jar.cbegin(), jar.cend(), 0);
  EXPECT_EQ(sum, 10);

  // the third arg is return type and start point of accumulation
  std::vector<std::string> strong = {"a", "b", "c"};
  std::string s = std::accumulate(strong.cbegin(), strong.cend(), std::string(""));
  EXPECT_EQ(s, "abc");
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
