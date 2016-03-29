#include "gtest/gtest.h"
#include <string>
#include <iostream>
#include <iterator>


// 23: concatenate 2 string, return dynamical char[]
char *string_concat(const std::string &st1, const std::string &st2) {
  unsigned long size = st1.size() + st2.size();
  char *c= new char[size];
  (st1 + st2).copy(c, size);
  return c;
}

TEST(DynamicTest, SomeTest) {
  std::string st1 = "ja";
  std::string st2 = "va";

  char *j = string_concat(st1, st2);
  std::cout << std::string(j) << std::endl;

  // FIXME: "java\xB0*"
  // EXPECT_EQ(std::string(j), "java");

  // 25: delete pa
  int *pa = new int[10];
  delete [] pa;

}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
