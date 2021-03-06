#include <deque>
#include <list>
#include <vector>
#include "gtest/gtest.h"


bool find_int_in_vector(std::vector<int> vv, int target) {
  for (int j : vv) {
    if (j == target) {
      return true;
    }
  }
  return false;
}

std::vector<int>::iterator get_int_in_vector(std::vector<int> &vv, int target) {
  std::vector<int>::iterator end = std::end(vv);
  for (std::vector<int>::iterator i = std::begin(vv); i != end; ++i) {
    if (*i == target) {
      return i;
    }
  }
  return end;
}


TEST(ContainerTest, SomeTest) {
  // 9.2 a list holding deque,
  // where these deques hold ints
  std::list<std::deque<int>> jar;

  // 9.4
  std::vector<int> vv = {1, 2, 3, 4, 5};
  EXPECT_EQ(find_int_in_vector(vv, 1), true);

  // 9.5
  auto result = get_int_in_vector(vv, 2);
  EXPECT_EQ(*result, 2);

  // 9.6: fix it
  std::list<int> lst1;
  std::list<int>::iterator iter1 = lst1.begin(), iter2 = lst1.end();
  // while (iter1 < iter2) // can't compare iterator
  // fix:
  while (iter1 != iter2) {
    ++iter1;
  }

}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
