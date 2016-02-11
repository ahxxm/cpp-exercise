#include "gtest/gtest.h"
#include <list>
#include <string>
#include <iostream>
#include <algorithm>

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

TEST(FindTest, SomeFindTest) {
  // 36:
  std::list<int> lst = {1, 2, 3, 4, 0, 5};
  auto result = std::find(lst.crbegin(), lst.crend(), 0);
  EXPECT_EQ(result.base() == lst.cend(), false);
}

std::list<int> copy_from_vector(const std::vector<int> &ve) {
  std::list<int> lst;
  if (ve.size() < 10) {
    return lst;
  }

  std::list<int> sub_ve(ve.begin() + 2, ve.begin() + 7);
  return sub_ve;
}

// 37: copy 3-7 reversely into a list
TEST(VectorReverseCopyTest, SomeVectorTest) {
  std::vector<int> ve = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> ve2 = {1, 2, 3};
  std::list<int> result = {3, 4, 5, 6, 7};
  std::list<int> blank_result;

  auto aa = copy_from_vector(ve);
  EXPECT_EQ(aa, result);

  auto bb = copy_from_vector(ve2);
  EXPECT_EQ(bb, blank_result);

}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
