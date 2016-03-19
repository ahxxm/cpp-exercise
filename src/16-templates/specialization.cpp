#include "gtest/gtest.h"
#include <iostream>


template <typename T>
int compare(const T&, const T&) {
  return 42;
};


// empty pair of brackets means specialization
// requires previously declared template to match
template <>
int compare(const char* const &p1, const char* const &p2) {
  return strcmp(p1, p2);
};


TEST(SpecializationTest, SomeTest) {
  // specialization instantiate a template
  // FIXME: no matching function...
  // std::cout << compare("j1", "j23") << std::endl;

  std::cout << strcmp("j1", "j23") << std::endl;
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
