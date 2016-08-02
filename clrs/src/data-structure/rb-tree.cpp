#include <cstdlib>
#include <cassert>
#include <memory>
#include <utility>
#include "gtest/gtest.h"

#include <iostream>

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
};


class RBTree {
public:
  using node_p = Node*;
  using link = node_p*;

  // TODO: protected for inherit class

  // constructor
  // default: make root black
  RBTree(): root(nullptr) {};

  ~RBTree() {
    // iteratively delete, then set root to null
    // clean(root);
    // root = nullptr;
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
    // pair: correct_pos, parent
    std::pair<link, node_p> position;
    position = get_insert_position(val);
    if(!position.first) {
      return;
    }

    // new node
    node_p node = new Node;
    node->value = val;
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


  // debug method for print tree
  auto getRoot() {
    return root;
  }

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
    if(!node) {return black;}
    return node->color;
  }

  std::pair<link, node_p> get_insert_position(int val) {
    // insert_pos is a pointer to correct nullptr
    // **insert_pos == nullptr(either node->left or right)

    // origin is its parent
    link insert_pos = make_link(root);
    node_p parent = nullptr;

    while(deref_link(insert_pos)) {
      // keep parent then make_link
      parent = deref_link(insert_pos);
      if(val < parent->value) {
        insert_pos = make_link(parent->left);
      } else {
        insert_pos = make_link(parent->right);
      }
    }

    return std::make_pair(insert_pos, parent);

  }

  node_p sib(node_p node) {
    auto parent = node->parent;
    auto si = parent->left;
    if(si == node) {si = parent->right;}
    return si;
  }

  int check(node_p node) {
    // returns black height
    // null leaft has 1
    if(!node) {return 1;}

    // 3. leaf are black(by design?)
    node_p left = node->left;
    node_p right = node->right;

    // 5. black height is same from node to every leaft node
    int left_height = check(left);
    int right_height = check(right);
    if(left_height != right_height) {
      std::cout << "node " << node->value << " is not balanced." << std::endl;
      assert(left_height == right_height);
    }

    // 4. no consecutive red node
    if(node_color(node) == red) {
      assert(node_color(left) == black);
      assert(node_color(right) == black);
    } else {
      // now node is black, height is left/right height + 1(self)
      ++left_height;
    }

    // make sure parent/child pair is correct
    if((left && left->parent != node) || (right && right->parent != node)) {
      assert(1 == 0);
    }

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
    node->right = nullptr;

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
    node->left = nullptr;

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
    root->color = black;
  }

  void insertfix_cases(node_p node) {
    auto parent = node->parent;
    auto si = sib(node);
    // complex case 1: sib is red
    // parent && sib both are previously red, grandpa must be black
    // sib can't have child(black height is 1)
    if(node_color(si) == red) {
      si->color = black;
      parent->color = red;

      // parent's parent is also red, recursively fix it
      if(node_color(parent->parent) == red) {
        parent->parent->color = black;
        insertfix_cases(parent->parent);
      }
    }

    // complex case 2: sib is nullptr
    // black height is also 1
    // set node to parent, set previous parent red
    else {
      std::cout << "fixing insert case 2 on node "
                << node->value
                << ", parent value "
                << parent->value << std::endl;

      parent->color = red;
      if(node == parent->left) {
        if(node_color(node->right) == red) {
          node->color = red;
          node->right->color = black;
          left_rotate(make_link(parent->left));
        }
        right_rotate(get_link(parent));
      } else {
        if(node_color(node->left) == red) {
          node->color = red;
          node->left->color = black;
          right_rotate(make_link(parent->right));
        }
        left_rotate(get_link(parent));
      }

    }

  };

  void delfix();

};

void print(Node *p, int start)
{
  start++;
  if (p->right)
    {
      print(p->right, start);
    }
  for (int i = 0; i <= start; i++)
    {
      std::cout << "    ";
    }
  char color = 'B';
  if(p && p->color == red) {color = 'R';}
  std::cout << p->value << "," << color << std::endl;
  if (p->left)
    {
      print(p->left, start);
    }
}



void test_insert(RBTree &tree) {
  // for (int i = 0;i < 100; ++i) {
  // int a = std::rand() % 10000;
  for (auto a: {1, 2, 3, 4, 5, 6, 7, 8}) {
    tree.insert(a);
    std::cout << a << std::endl;
    print(tree.getRoot(), 0);
    tree.check();

  }
}

/*
void test_delete(RBTree &tree) {
  for (int i = 0;i < 600; ++i) {
    auto tmp = rand();
    tree.del(tmp);
    tree.check();
  }

  }
*/


TEST(RBTreeTest, SomeTest) {
  auto a = RBTree();
  test_insert(a);
  // test_delete(a);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
  // auto a = RBTree();
  // test_insert(a);
  // return 0;
}
