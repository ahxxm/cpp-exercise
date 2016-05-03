#include <iostream>
#include <random>
#include "gtest/gtest.h"


TEST(RandomNumberTest, SomeTest) {
  // seed value 42
  std::default_random_engine e(42);
  for (std::size_t i = 0;i < 10; ++i) {
    std::cout << e() << std::endl;
  };

  // !
  std::uniform_real_distribution<double> u(0, 1);
  for (std::size_t i = 0;i < 10; ++i) {
    std::cout << u(e) << std::endl;
  };
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
