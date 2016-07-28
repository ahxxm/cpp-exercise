#include <memory>
#include "gtest/gtest.h"

// TODO: ctor
// successor/predesessor
// TODO: display?
// TODO: chap problems and exercises

enum color {RED = false, BLACK = true};

template <typename T>
struct Node {
  T value;
  enum color color;

  typedef Node* node_p;
  node_p left, right, parent;

  auto min(node_p node) {
    while(node->left) {
      node = node->left;
    }
    return node;
  }

  auto max(node_p node) {
    while(node->right) {
      node = node->right;
    }
    return node;
  }

  auto grandp() {
    auto p = this->parent;
    if (p) {
      return p->parent;
    }
    return p;
  }

  auto uncle() {
    auto grandparent = this->grandp();
    if (!grandparent) {
      return grandparent;
    }

    if(this->parent == grandparent->left) {
      return grandparent->right;
    } else {
      return grandparent->left;
    }
  }

  Node(T val) {
    left = nullptr;
    right = nullptr;
    parent = nullptr;
    value = val;
    color = RED;
  }
};


template <typename T>
class RBTree {
public:
  typedef T value_type;
  typedef T* pointer;
  using node_p = Node<T>*;

  void insert();
  void insertfix();
  void del(node_p node);
  void delfix();
  void left_rotate(node_p parent);
  void right_rotate(node_p parent);
  int black_height(node_p node);
  node_p search(T val);

private:
  node_p root;
  int size;
};



TEST(RBTreeTest, SomeTest) {
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
