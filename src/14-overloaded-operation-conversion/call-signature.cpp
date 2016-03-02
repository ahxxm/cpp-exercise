#include "gtest/gtest.h"
#include <map>
#include <string>
#include <utility>

int adder(int &i, int &j) {
  return i + j;
}

int ( * add)(int &i, int &j) = adder;

TEST(SignatureTest, SomeTest) {
  std::map<std::string, int(*)(int &, int&)> binops;
  auto mapper = std::pair<std::string, int(*)(int &, int&)> {"+", add};
  binops.insert({"+", add});
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest( & argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
