#include <string>
#include <vector>
#include "gtest/gtest.h"

void push() {
  std::vector<std::string> vs;

  // theated as: vs.push_back(std::string("aa"))
  // vs.push_back("aa");

  // total: 2 constructor, 1 destructor
  // - std::string tmp {"aa"};
  // - rvalue tmp passed to push_back, another construction
  // - destroy tmp

  // correct function to use:
  // it uses perfect forwarding.
  // push_back takes **object**, emplace_back takes **constructor args**.
  vs.emplace_back("aa");

}

TEST(EmplaceTest, SomeTest) {
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
