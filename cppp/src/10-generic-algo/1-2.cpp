#include <algorithm>
#include <iostream>
#include <vector>
#include "gtest/gtest.h"



TEST(AlgoIntroTest, SomeTest) {
  std::vector<int> jar = {1, 2, 3, 42, 50};
  int val = 42;
  auto result = std::find(jar.cbegin(), jar.cend(), val);
  EXPECT_EQ(result != jar.cend(), true);

  // 1 2: count value
  int c = std::count(jar.cbegin(), jar.cend(), val);
  EXPECT_EQ(c, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
