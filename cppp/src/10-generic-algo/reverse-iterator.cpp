#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include "gtest/gtest.h"


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

  // in place sort
  // list itself does not support std::sort
  lst.sort();
  std::list<int> sorted_lst = {0, 1, 2, 3, 4, 5};
  EXPECT_EQ(lst, sorted_lst);

  std::list<int> lst_2 = {7, 8, 9};
  lst.merge(lst_2);
  std::list<int> merged_lst = {0, 1, 2, 3, 4, 5, 7, 8, 9};

  // merge/splice will DESTROY the given args..
  // now lst_2 is a blank list..
  std::list<int> blank_lst;
  EXPECT_EQ(lst, merged_lst);
  EXPECT_EQ(lst_2, blank_lst);

  std::list<int> reverse_lst = {9, 8, 7, 5, 4, 3, 2, 1, 0};
  lst.reverse();
  EXPECT_EQ(lst, reverse_lst);



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
