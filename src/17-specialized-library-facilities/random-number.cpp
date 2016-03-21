#include "gtest/gtest.h"
#include <random>
#include <iostream>


TEST(RandomNumberTest, SomeTest) {
  // seed value 42
  std::default_random_engine e(42);
  for (std::size_t i = 0;i < 10; ++i) {
    std::cout << e() << std::endl;
  }
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
