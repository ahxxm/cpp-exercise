#include <iostream>
#include <memory>
#include <stack>
#include "gtest/gtest.h"

// TODO: build, del, prede/suc cessor, depth, mirror
// AVL tree/treap
// TODO: balanced binary tree? Day-Stout-Warren algorithm https://github.com/DChaushev/Advanced-Data-Structures


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

  void post_order() {
    post_order(root);
    std::cout << std::endl;
  }

  // successor and predecessor
  node_t *successor(node_t *node) {
    if(!node) {return nullptr;}
    if(node->right) {
      return min(node->right);
    }

    node_t *p = node->parent;
    while(p && node != p->left) {
      node = p;
      p = node->parent;
    }
    return p;
  }

  node_t *predecessor(node_t *node) {
    if(!node) {return nullptr;}
    if(node->left) {
      return max(node->left);
    }

    node_t *p = node->parent;
    while(p && node != p->right) {
      node = p;
      p = node->parent;
    }
    return p;
  }


  auto min() {return min(root);}
  auto max() {return max(root);}


  // TODO:
  void balance(); // balance the whole tree
  // int height(); // impl after balance?
  // void rotate_left(); // and right

private:
  int size = 0;
  node_t *root;

  node_t *min(node_t *iter) {
    node_t *result;
    while(iter) {
      result = iter;
      iter = iter->left;
    }
    return result;
  }

  node_t *max(node_t *iter) {
    node_t *result;
    while(iter) {
      result = iter;
      iter = iter->right;
    }
    return result;
  }

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

  // iterative
  void pre_order(node_t *node) {
    if (!node) {return;}
    std::stack<node_t *> s;
    s.push(node);

    while(!s.empty()) {
      node = s.top();
      s.pop();
      std::cout << node->value << " ";
      if(node->right) {
        s.push(node->right);
      }
      if(node->left) {
        s.push(node->left);
      }
    }
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

  void post_order(node_t *node) {
    std::stack<node_t *> s;
    node_t *last_visited;
    while(!s.empty() || node) {
      if(node) {
        s.push(node);
        node = node->left;
      } else {
        auto top = s.top();
        if(top->right && last_visited != top->right) {
          node = top->right;
        } else {
          std::cout << top->value << " ";
          last_visited = top;
          s.pop();
        }
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

  //    3
  //  1   5
  // 0 2 4 6

  auto b = a.search(5);
  EXPECT_EQ(b->value, 5);
  EXPECT_EQ(b->parent->value, 3);
  EXPECT_EQ(b->left->value, 4);
  EXPECT_EQ(b->right->value, 6);
  EXPECT_EQ(a.successor(b)->value, 6);
  EXPECT_EQ(a.predecessor(b)->value, 4);

  auto c = a.search(1);
  EXPECT_EQ(c->value, 1);
  EXPECT_EQ(c->parent->value, 3);
  EXPECT_EQ(c->left->value, 0);
  EXPECT_EQ(c->right->value, 2);
  EXPECT_EQ(a.successor(c)->value, 2);
  EXPECT_EQ(a.predecessor(c)->value, 0);

  a.pre_order();
  a.in_order();
  a.post_order();


  EXPECT_EQ(a.min()->value, 0);
  EXPECT_EQ(a.max()->value, 6);

}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
