#include "rb-tree.h"
#include "gtest/gtest.h"

class set {
public:
  // construct/copy/destruct
  set(): ImplTree() {}

  // public member functions
  bool empty() {
    return ImplTree.getSize() == 0;
  };

  std::size_t size() {
    return ImplTree.getSize();
  };

  // TODO:
  set(const set &) = delete;
  set &operator=(std::initializer_list<int>) = delete;
  // emplace
  // const_iterator find(const key_type &) const;
  // size_type count(const key_type &) const;
  // size_type count(const key_type &);
  // insert/emplace, TODO: difference?
  // del
  // min
  // max


  // public data members
private:
  using rep_type = RBTree;
  rep_type ImplTree;
};




TEST(SetTest, SomeTest) {
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
