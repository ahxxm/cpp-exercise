#include <cstdlib>
#include <cassert>
#include <memory>
#include "gtest/gtest.h"

// TODO: display?
// TODO: chap problems and exercises

// color for tree
#define black true
#define red false

struct Node {
  int value;
  bool color;

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

  Node(int val) {
    left = nullptr;
    right = nullptr;
    parent = nullptr;
    value = val;
    color = black;
  }
};


class RBTree {
public:
  using node_p = Node*;

  // TODO: protected for inherit class

  // constructor
  // default: make root black
  RBTree() {
    root->color = black;
  }

  ~RBTree() {
    // iteratively delete, then set root to null
    delete_node(root);
    root = nullptr;
  }

  node_p search(const int &val) {
    auto iter = root;
    while(iter) {
      if(iter->value == val) {
        return iter;
      }

      if(iter->value > val) {
        iter = iter->left;
      } else {
        iter = iter->right;
      }
    }
    return iter;
  }

  void insert(int val);
  void del(node_p node);
  void del(int val);
  int black_height(node_p node);


  void check() {
    // 1. nodes are red or black
    // 2. root black
    if(node_color(root) == red) {
      // TODO: throw
    }

    check(root);
  };

private:
  node_p root;
  int size;

  void delete_node(node_p node) {
    if(node) {
      delete_node(node->left);
      delete_node(node->right);
      delete node;
    }
  }

  bool node_color(node_p node) {
    if(node) {
      return node->color;
    }
    return black;
  }

  int check(node_p node) {
    // returns black height
    if(!node) {return 1;}

    // 3. leaf are black(by design?)
    // 4. no consecutive red node
    auto left = node->left;
    auto right = node->right;
    if(node->color == red) {
      assert(left->color == black);
      assert(right->color == black);
    }

    // make sure parent/child pair is correct
    if((left && left->parent != node) || (right && right->parent != node)) {
      assert(1 == 0);
    }

    // 5. black height is same from node to every leaft node
    int left_height = check(left);
    int right_height = check(right);
    assert(left_height == right_height);

    // now node is black, height is left/right height + 1(self)
    ++left_height;

    return left_height;

  }

  void insertfix();
  void delfix();
  void left_rotate(node_p parent);
  void right_rotate(node_p parent);
};


void test_insert(RBTree &tree) {
  for (int i = 0;i < 500; ++i) {
    int a = std::rand() % 10000;
    tree.insert(a);
    tree.check();
  }
}

void test_delete(RBTree &tree) {
  for (int i = 0;i < 600; ++i) {
    auto tmp = rand();
    tree.del(tmp);
    tree.check();
  }

}

TEST(RBTreeTest, SomeTest) {
  auto a = RBTree();
  test_insert(a);
  test_delete(a);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
