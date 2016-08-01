#include <cstdlib>
#include <cassert>
#include <memory>
#include <utility>
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
  using link = node_p*;

  // TODO: protected for inherit class

  // constructor
  // default: make root black
  RBTree() {
    root->color = black;
  }

  ~RBTree() {
    // iteratively delete, then set root to null
    clean(root);
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

  void insert(int val) {
    auto position = get_insert_position(val);
    if(!position.first) {
      return;
    }

    // new node
    node_p node = new Node(val);
    node->color = red;
    node->left = nullptr;
    node->right = nullptr;
    node->parent = position.second;

    // set to position
    set_link(position.first, node);

    // fix color..
    insertfix(node);
  }

  void check() {
    // 1. nodes are red or black
    // 2. root black
    if(node_color(root) == red) {
      assert(1 == 0);
    }

    check(root);
  };

  void del(node_p node);
  void del(int val);
  int black_height(node_p node);

private:
  node_p root;
  int size;

  void clean(node_p node) {
    // helper for root(only)
    if(node) {
      clean(node->left);
      clean(node->right);
      delete node;
    }
  }

  bool node_color(node_p node) {
    if(node) {
      return node->color;
    }
    return black;
  }

  std::pair<link, node_p> get_insert_position(int val) {
    auto where = make_link(root);
    node_p origin = nullptr;

    while(deref_link(where)) {
      origin = deref_link(where);
      if(val < origin->value) {
        where = make_link(origin->left);
      } else if(val > origin->value) {
        where = make_link(origin->right);
      } else {
        where = nullptr;
        break;
      }
    }

    return std::make_pair(where, origin);
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

  // link is node**
  link make_link(node_p &node) {return &node;}
  node_p deref_link(link __link) {return *__link;}
  void set_link(link __link, node_p node) {*__link = node;}
  node_p get_link_parent_node(link __link) {return deref_link(__link)->parent;}
  link get_link(node_p node) {
    node_p parent = node->parent;
    if(!parent) {
      return make_link(root);
    }
    if(parent->left == node) {
      return make_link(parent->left);
    }
    return make_link(parent->right);
  }

  // rotate
  void left_rotate(link parent) {
    // counter-clockwise
    // make parent a left child, make its origin right child parent
    auto node = deref_link(parent);
    auto right = node->right;
    auto rleft = right->left;

    set_link(parent, right);
    right->parent = node->parent;
    right->left = node;
    node->parent = right;

    if(rleft) {
      rleft->parent = node;
    }
  }

  void right_rotate(link parent) {
    // mirror to left rotate
    auto node = deref_link(parent);
    auto left = node->left;
    auto lright = left->right;

    set_link(parent, left);
    left->parent = node->parent;
    left->right = node;
    node->parent = left;

    if(lright) {
      lright->parent = node;
    }
  }

  // fix color
  void insertfix(node_p node) {
    // case 1: new tree
    if(!node->parent) {
      node->color = black;
      return;
    }

    // case 2: parent black
    if(node->parent->color == black) {
      return;
    }

    // otherwise, make parent black, then rebalance
    // on upwards
    node->parent->color = black;
    insertfix_cases(node->parent);
  }

  void insertfix_cases(node_p node) {

  };

  void delfix();

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
