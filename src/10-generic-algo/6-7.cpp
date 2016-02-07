#include "gtest/gtest.h"
#include <algorithm>
#include <list>


TEST(CopyTest, SomeTest) {
  // must have same type?
  std::list<int> ll;
  std::list<int> lst = {1, 2, 3, 4, 5};
  std::copy(lst.begin(), lst.end(), ll.begin());
  EXPECT_EQ(ll.back(), 5);

  // 6: fill_n to 0
  std::vector<int> vec = {1, 2, 3, 4, 5};
  size_t length = vec.size();
  std::fill_n(vec.begin(), length, 0);
  EXPECT_EQ(vec.back(), 0);

  // 7: correct error
  // a
  std::vector<int> va;
  std::list<int> lis = {5, 4, 3, 2, 1};
  // std::copy(lst.cbegin(), lst.cent(), va.begin());
  // should use back_inserter, copy value from list to vector
  // (begin, end, destiny)
  std::copy(lis.begin(), lis.end(), std::back_inserter(va));
  EXPECT_EQ(va[0], 5);

  // b
  std::vector<int> vb;
  // vb.reserve(10); // does not expand its size
  vb.resize(10);
  std::fill_n(vb.begin(), 10, 0);
  EXPECT_EQ(vb[9], 0);

}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
