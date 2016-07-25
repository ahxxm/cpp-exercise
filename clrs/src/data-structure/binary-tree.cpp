#include <iostream>
#include <memory>
#include "gtest/gtest.h"

// TODO: build, insert, del, search, min, max, prede/suc cessor, size, depth, mirror
// AVL tree/treap
// TODO: balanced binary tree?


template <typename T>
struct Node {
  T value;
  Node<T> *left;
  Node<T> *right;

  Node(T val): value(val){};

};


template <typename T>
class BinaryTree {
public:
  // constructor
  // TODO: build from std::vector<T>, or first/last iterator to be more generic?

  // interface
  void insert(T val) {
    insert(root, val);
  };

  int node_count() {return size;}
  bool is_empty() {return size == 0;}

  // TODO:
  void pre_order(); // pre/in/post order traversal, test
  void print();
  void balance(); // balance the whole tree
  // node_t *search(T val) ;
  // int height(); // impl after balance
  // void rotate_left(); // and right

private:
  using node_t = Node <T>;

  node_t *root;
  int size = 0;

  void insert(node_t *node, T val) {
    // insert below this parent
    // actual insert
    if (!node) {
      node = new node_t(val);
      node->left = nullptr;
      node->right = nullptr;
      size += 1;
      return;
    }

    // find nullptr
    if (val < node->value) {
      insert(node->left, val);
    } else {
      insert(node->right, val);
    }
  }

};


TEST(BinarySearchTreeTest, SomeTest) {
  auto a = BinaryTree<int>();
  a.insert(3);
  a.insert(1);
  a.insert(2);
  a.insert(5);
  a.insert(4);
  EXPECT_EQ(a.node_count(), 5);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
