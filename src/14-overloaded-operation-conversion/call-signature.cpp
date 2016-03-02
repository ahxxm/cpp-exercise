#include "gtest/gtest.h"
#include <map>
#include <string>
#include <utility>
#include <functional>

int adder(int &i, int &j) {
  return i + j;
}

int (*add)(int &i, int &j) = adder;

TEST(SignatureTest, SomeTest) {
  std::map<std::string, int(*)(int &, int&)> binops;
  auto mapper = std::pair<std::string, int(*)(int &, int&)> {"+", add};
  binops.insert(mapper);

  // null function object to store callable objects
  // with call signature..
  std::function<int(int &, int &)> f;
  std::function<int(int &, int &)> f1(nullptr);
  std::function<int(int, int)> f2 = [](int i, int j) {return i + j;};
  EXPECT_EQ(f2(1, 5), 6);

}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest( & argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
