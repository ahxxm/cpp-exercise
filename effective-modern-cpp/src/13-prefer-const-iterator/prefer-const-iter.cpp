#include <algorithm>
#include <iterator>
#include <vector>
#include "gtest/gtest.h"

// use const whenever practical

// const iterator: STL equivalent to const pointer

// non-member cbegin/cend because C++11 does not have std::cbegin/cend
template<class C>
auto cbegin(const C& container)->decltype(std::begin(container)) {
  return std::begin(container);
}

template<class C>
auto cend(const C& container)->decltype(std::end(container)) {
  return std::end(container);
}


TEST(ConstIterTest, SomeTest) {

  std::vector<int> v {1, 2, 3, 4};
  auto it = std::find(cbegin(v), cend(v), 4);

  // insert before,{1,2,3,5,4}
  v.insert(it, 5);
  EXPECT_EQ(static_cast<int>(v.size()), 5);
  EXPECT_EQ(v[3], 5);
  EXPECT_EQ(v[4], 4);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
