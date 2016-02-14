#include "gtest/gtest.h"
#include <memory>
#include <string>
#include <iostream>


TEST(SmartPointerTest, SomeTest) {
  // type is std::shared_ptr<int>
  auto p = std::make_shared<int>(42);
  EXPECT_EQ(*p, 42);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
