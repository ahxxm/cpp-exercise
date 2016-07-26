#include <iostream>
#include <memory>
#include <stack>
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

  Node(T val): value(val){
    left = nullptr;
    right = nullptr;
    parent = nullptr;
  };

};


template <typename T>
class BinaryTree {
public:
  using node_t = Node <T>;

  // constructor
  // TODO: build from std::vector<T>, or first/last iterator to be more generic?
  BinaryTree(): root(nullptr) {}

  // TODO: destructor release all ptr from new

  // interface
  auto insert(T val) {
    if (!root) {
      root = insert(root, nullptr, val, 0);
      return root;
    }

    auto node = insert(root, nullptr, val, 0);
    return node;
  };

  int node_count() {return size;}
  bool is_empty() {return size == 0;}

  node_t *search(T val) {
    auto iter = root;
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

  // pre/in/post order traversal
  void pre_order() {
    pre_order(root);
    std::cout << std::endl;
  };

  void in_order() {
    in_order(root);
    std::cout << std::endl;
  };


  // TODO:
  void balance(); // balance the whole tree
  void print();
  // int height(); // impl after balance?
  // void rotate_left(); // and right

private:
  int size = 0;
  node_t *root;

  auto insert(node_t *node, node_t *parent, T val, int left = 0) {
    // insert below this parent
    // actual insert
    if (!node) {
      auto t = new node_t(val);
      t->left = nullptr;
      t->right = nullptr;
      size += 1;

      if(!parent) {return t;}
      t->parent = parent;
      if (left) {
        parent->left = t;
      } else {
        parent->right = t;
      }
      return t;
    }

    // find position
    if (val < node->value) {
      return insert(node->left, node, val, 1);
    } else {
      return insert(node->right, node, val, 0);
    }
  }

  // recursive pre_order
  void pre_order(node_t *node) {
    if(!node) {return;}
    std::cout << node->value << " ";
    pre_order(node->left);
    pre_order(node->right);
  }

  // iterative in_order using std::stack
  void in_order(node_t *node) {
    std::stack<node_t *> s;
    while(!s.empty() || node) {
      if(node) {
        s.push(node);
        node = node->left;
      } else {
        node = s.top();
        std::cout << node->value << " ";
        s.pop();
        node = node->right;
      }
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
  a.insert(6);
  a.insert(0);
  EXPECT_EQ(a.node_count(), 7);
  // a.print();

  //    3
  //  1   5
  // 0 2 4 6

  auto b = a.search(5);
  EXPECT_EQ(b->value, 5);
  EXPECT_EQ(b->parent->value, 3);
  EXPECT_EQ(b->left->value, 4);
  EXPECT_EQ(b->right->value, 6);

  auto c = a.search(1);
  EXPECT_EQ(c->value, 1);
  EXPECT_EQ(c->parent->value, 3);
  EXPECT_EQ(c->left->value, 0);
  EXPECT_EQ(c->right->value, 2);

  a.pre_order();
  a.in_order();

  // a.postorder();

}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
