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
  Node<T> *parent;

  Node(T val): value(val){};

};


template <typename T>
class BinaryTree {
public:
  using node_t = Node <T>;

  // constructor
  // TODO: build from std::vector<T>, or first/last iterator to be more generic?

  // interface
  void insert(T val) {
    insert(root, nullptr, val, 0);
  };

  int node_count() {return size;}
  bool is_empty() {return size == 0;}

  // FIXME: test
  node_t *search(T val) {
    std::cout << root->value << std::endl;
    auto iter = root;
    std::cout << iter->value << std::endl;
    while(iter) {
      if (iter->value == val) {
        break;
      }

      if (iter->value > val) {
        iter = iter->left;
      } else {
        iter = iter->right;
      }
    }

    return iter;
  }


  void postorder() {
    postorder(root, 0);
  }

  // TODO:
  void pre_order(); // pre/in/post order traversal, test
  void balance(); // balance the whole tree
  void print();
  // int height(); // impl after balance?
  // void rotate_left(); // and right

private:
  int size = 0;
  node_t *root;

  void insert(node_t *node, node_t *parent, T val, int left = 0) {
    // insert below this parent
    // actual insert
    if (!node) {
      node = new node_t(val);
      node->left = nullptr;
      node->right = nullptr;
      size += 1;

      if(!parent) {return;}
      if (left) {
        parent->left = node;
      } else {
        parent->right = node;
      }
      return;
    }

    // find position
    if (val < node->value) {
      insert(node->left, node, val, 1);
    } else {
      insert(node->right, node, val, 0);
    }
  }

  void postorder(node_t *p, int indent = 0)
  {
    if(p) {
      if(p->left) {
        postorder(p->left, indent + 4);
      }
      if(p->right) {
        postorder(p->right, indent + 4);
      }

      if(indent) {
        std::cout << std::setw(indent) << ' ';
      }
      std::cout << p->value << "\n ";
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

  // a.postorder();
  // auto b = a.search(5);
  // EXPECT_EQ(b->value, 5);
  // EXPECT_EQ(b->left->value, 4);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
