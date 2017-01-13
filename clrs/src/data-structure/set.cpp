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

  auto size() {
    return ImplTree.getSize();
  };

  bool find(int i) {
    auto node_p = ImplTree.search(i);
    if (node_p) {return true;}
    return false;
  }

  bool emplace(int i) {
    auto node_p = ImplTree.search(i);
    if (node_p) {return false;}
    ImplTree.insert(i);
    return true;
  }

  // TODO:
  // set &operator=(std::initializer_list<int>) = delete;
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
  auto s = set();
  EXPECT_EQ(s.size(), 0);
  s.emplace(1);
  EXPECT_EQ(s.size(), 1);
  EXPECT_EQ(s.find(1), true);
  EXPECT_EQ(s.find(2), false);

  s.emplace(1);
  EXPECT_EQ(s.size(), 1);
  EXPECT_EQ(s.find(1), true);
  s.emplace(2);
  EXPECT_EQ(s.size(), 2);
  EXPECT_EQ(s.find(2), true);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
