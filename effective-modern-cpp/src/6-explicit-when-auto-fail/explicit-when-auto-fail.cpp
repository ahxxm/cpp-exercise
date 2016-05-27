#include <vector>
#include "gtest/gtest.h"


static std::vector<bool> wat = {true, false};

std::vector<bool> features(const int&) {
  return wat;
};


void fail() {
  auto w = 1;

  // jar could be a dangling pointer, depends on implementation of std::vector<bool>::reference.
  // here auto fail because [] returns:
  // 1 bit per bool in vector<bool>, ref to bool is forbidden in cpp.

  // bool jar = features(w)[1];
  // solution: cast
  auto jar = static_cast<bool>(features(w)[1]);
  std::cout << &jar << std::endl;

}


TEST(ExplicitTest, SomeTest) {
  fail();
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
