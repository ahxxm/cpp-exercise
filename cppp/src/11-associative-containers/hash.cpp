#include <vector>
#include <iostream>
#include <functional>
#include <string>
#include "gtest/gtest.h"


TEST(HashTest, SomeTest) {
  auto result = std::hash<std::string>()("java");
  auto result2 = std::hash<std::string>()("java");
  std::cout << result << std::endl;
  std::cout << result2 << std::endl;
  EXPECT_EQ(result, result2);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
