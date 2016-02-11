#include "gtest/gtest.h"
#include <vector>
#include <string>
#include <iostream>

// 34
void print_vector_reversely(std::vector<std::string> sa) {
  for (auto r_last = sa.rbegin(); r_last != sa.crend(); ++r_last) {
    std::cout <<* r_last<< std::endl;
  }
}


TEST(ReverseIteratorTest, SomeTest) {
  std::vector<std::string> sa = {"123", "456", "789"};
  print_vector_reversely(sa);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
