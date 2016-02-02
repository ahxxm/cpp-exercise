#include "gtest/gtest.h"
#include <deque>
#include <list>
#include <vector>

bool find_int_in_vector(std::vector<int> vv, int target) {
  for (int j: vv) {
    if (j == target) {
      return true;
    }
  }
  return false;
}

std::vector<int>::iterator get_int_in_vector(std::vector<int> vv, int target) {
  std::vector<int>::iterator end = std::end(vv);
  for (std::vector<int>::iterator i = std::begin(vv); i != end; ++i) {
    if (*i == target) {
      return i;
    }
  }
  return end;
}


TEST(ContainerTest, SomeTest) {
  EXPECT_EQ(1, 1);
  // 9.1 vector, deque, or a (linked) list?
  // (a): list then convert, or vector then sort,
  // or associative containers <= FIXME
  // (b): deque
  // (c): vector then sort

  // 9.2 a list holding deque,
  // where these deques hold ints
  std::list<std::deque<int>> jar;

  // 9.3
  std::vector<int> vv = {1, 2, 3, 4, 5};
  EXPECT_EQ(find_int_in_vector(vv, 1), true);

  auto result = get_int_in_vector(vv, 2);
  EXPECT_EQ(*result, 2);

}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
