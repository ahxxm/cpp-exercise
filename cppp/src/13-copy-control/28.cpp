#include "gtest/gtest.h"
#include <string>


// 28: implement default constructor
// and necessary copy contro lmembers

class TreeNode {
public:
  TreeNode(): value(std::string()), count(0) {};
  TreeNode(const TreeNode &tn): value(tn.value), count(tn.count), left(tn.left), right(tn.right) {};
  TreeNode &operator=(const TreeNode &tn) {
    value = tn.value;
    count = tn.count;
    TreeNode tl = *tn.left;
    TreeNode tr = *tn.right;
    left = &tl;
    right = &tr;
    return *this;
  };

  ~TreeNode() {};
private:
  std::string value;
  int count;
  TreeNode *left;
  TreeNode *right;
};

class BinStrTree {
public:
  BinStrTree(): root(new TreeNode()){};
  BinStrTree(const BinStrTree &bt) {
    TreeNode node = *bt.root;
    root = &node;
  };

  BinStrTree &operator=(const BinStrTree &bt) {
    TreeNode node = *bt.root;
    root = &node;
    return *this;
  };

  ~BinStrTree() {};
private:
  TreeNode *root;
};


TEST(ConstructorTest, SomeTest) {
  TreeNode a;
  TreeNode b(a);
  TreeNode c = b;

  BinStrTree d;
  BinStrTree e(d);
  BinStrTree f = e;
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
