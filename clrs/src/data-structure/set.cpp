#include "gtest/gtest.h"

// TODO: stl_set uses RBTree as backend
// TODO: search, insert, del, min, max, predecessor/successor(ordered set),

template<typename T>
class set {
public:
  // construct/copy/destruct
  set();
  set(const set &);

  // public member functions
  bool empty() const;
  std::size_t size() const;

  // emplace
  // const_iterator find(const key_type &) const;
  // size_type count(const key_type &) const;
  // size_type count(const key_type &);
  // insert


  // public data members
  const T& x;
};




TEST(SetTest, SomeTest) {
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
