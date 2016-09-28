#include "gtest/gtest.h"
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/lexical_cast.hpp>


using ll = boost::multiprecision::int1024_t;

int solve() {
  ll u = 1;
  for (int i = 1; i <= 100; ++i) {
    u *= i;
  }

  int result = 0;
  auto str = boost::lexical_cast<std::string> (u);
  for (auto i : str) {
    result += boost::lexical_cast<int> (i);
  }
  return result;
}


TEST(FactorialDigitTest, SomeTest) {
  // std::cout << solve() << std::endl;
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
