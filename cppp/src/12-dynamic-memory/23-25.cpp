#include <stdio.h>
#include <iostream>
#include <iterator>
#include <string>
#include "gtest/gtest.h"


// 23: concatenate 2 string, return dynamical char[]
char *string_concat(const std::string &st1, const std::string &st2) {
  uint64_t size = st1.size() + st2.size();
  char *c = new char[size];

  // snprintf is suggested to replace strcpy,
  // although size_t includes terminating null char.
  // strcpy(c, (st1 + st2).c_str());
  int cx = snprintf(c, size + 1, "%s%s", st1.c_str(), st2.c_str());
  std::cout << cx << std::endl;
  return c;
}

TEST(DynamicTest, SomeTest) {
  std::string st1 = "ja";
  std::string st2 = "va";

  char *j = string_concat(st1, st2);
  std::string j_str(j);
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
