#include "gtest/gtest.h"
#include <functional>
#include <string>

bool isLonger(std::string &s, std::size_t sz) {
  return s.size() > sz;
}

TEST(BindTest, SomeTest) {
  auto newIsLonger = std::bind(isLonger, std::placeholders::_1, 2);
  std::string st = "12345";
  EXPECT_EQ(newIsLonger(st), true);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
