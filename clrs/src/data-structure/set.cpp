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

  bool add(int i) {
    auto node_p = ImplTree.search(i);
    if (node_p) {return false;}
    ImplTree.insert(i);
    return true;
  }

  bool del(int i) {
    return ImplTree.del(i);
  }

private:
  RBTree ImplTree;
};




TEST(SetTest, SomeTest) {
  auto s = set();
  EXPECT_EQ(s.size(), 0);
  s.add(1);
  EXPECT_EQ(s.size(), 1);
  EXPECT_EQ(s.find(1), true);
  EXPECT_EQ(s.find(2), false);

  s.add(1);
  EXPECT_EQ(s.size(), 1);
  EXPECT_EQ(s.find(1), true);
  s.add(2);
  EXPECT_EQ(s.size(), 2);
  EXPECT_EQ(s.find(2), true);

  auto rst = s.del(2);
  EXPECT_EQ(rst, true);
  EXPECT_EQ(s.size(), 1);

  auto rst_2 = s.del(3);
  EXPECT_EQ(rst_2, false);
  EXPECT_EQ(s.size(), 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
