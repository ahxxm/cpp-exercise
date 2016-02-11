#include "gtest/gtest.h"
#include <vector>
#include <string>
#include <iostream>

// 34
void print_vector_reversely(const std::vector<std::string> &sa) {
  for (auto r_last = sa.rbegin(); r_last != sa.crend(); ++r_last) {
    std::cout << *r_last << std::endl;
  }
}

// 35
void print_vector_reversely_using_ordinary_iterator(const std::vector<std::string> &sa) {
  for (auto r_last = sa.end(); r_last != sa.cend(); --r_last) {
    std::cout << *r_last << std::endl;
  }
}


TEST(ReverseIteratorTest, SomeTest) {
  std::vector<std::string> sa = {"123", "456", "789"};
  print_vector_reversely(sa);
  print_vector_reversely_using_ordinary_iterator(sa);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
