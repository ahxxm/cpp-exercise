#include <stdio.h>
#include <iostream>
#include <iterator>
#include <string>
#include "gtest/gtest.h"


// 23: concatenate 2 string
// use stringstream instead of (return dynamical char[])
auto string_concat(const std::string &st1, const std::string &st2) {
  std::stringstream stream;
  stream << st1 << st2;
  return stream.str();
}

TEST(DynamicTest, SomeTest) {
  std::string st1 = "ja";
  std::string st2 = "va";

  auto j_str = string_concat(st1, st2);
  std::cout << j_str << std::endl;

  EXPECT_EQ(j_str, "java");

  // 25: delete pa
  int *pa = new int[10];
  delete [] pa;

}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
