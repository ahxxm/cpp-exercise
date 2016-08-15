#include <cstdlib>
#include <cassert>
#include <memory>
#include <utility>
#include "gtest/gtest.h"

#include <iostream>

// TODO: chap problems and exercises

// color for tree
#define black true
#define red false

struct Node;
typedef Node* node_p;

struct Node {
  int value;
  bool color;
  node_p left, right, parent;



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


// return left-most/right-most,
// could return origin
auto rleft_most(node_p node) {
  // the smallest node that value greater than `node`
  while(node->left) {
    node = node->left;
  }
  return node;
}

auto lright_most(node_p node) {
  while(node->right) {
    node = node->right;
  }
  return node;
}


void print(Node *p, int start) {
  // node print in "value, R/B" form
  // left most node is root
  // node value descendingly ordered from top to bottom
  if(!p) {return;}
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


class RBTree {
public:
  using link = node_p*;

  // TODO: protected for inherit class

  // constructor
  // default: make root black
  RBTree(): root(nullptr) {};

  ~RBTree() {
    // iteratively delete, then set root to null
    clean(root);
    root = nullptr;
  }

  node_p search(const int val) {
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

  void del(const int val) {
    // not found
    auto k = search(val);
    if(!k) {return;}

    // otherwise
    auto node = swap_and_return_remove(k);

    // fix
    delfix(node);

    // clean memory
    delete node;
  }

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

  // link is node**, pointer is sometimes copied while passing by value,
  // this restores origin pointer address.

  // make_link/get_link: pointer to node_p in tree
  // set_link: replace node_p in tree with new pointer
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

    node->right = right->left;
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

    node->left = left->right;
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
    root->color = black;
  }

  void insertfix_cases(node_p node) {
    auto parent = node->parent;
    auto si = sib(node);
    // complex case 1: sib is red
    if(node_color(si) == red) {
      si->color = black;
      parent->color = red;
      // parent's parent is also red, recursively fix it
      if(node_color(parent->parent) == red) {
        parent->parent->color = black;
        insertfix_cases(parent->parent);
      }
    }

    // complex case 2: sib is black
    else {
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


  node_p swap_and_return_remove(node_p node) {
    // case 1: swap node with left-most-of-right,
    // return to-delete-node
    node_p result = nullptr;
    if(node->left && node->right) {
      result = rleft_most(node);
      std::swap(result->value, node->value);
      node = result;
      result = nullptr;
    }

    // case 2: only 1 child, swap and reset parent
    if(node->left) {
      result = node->left;
    } else if (node->right){
      result = node->right;
    }

    set_link(get_link(node), result);
    if(result) {
      result->parent = node->parent;
    }

    return node;
  }

  void delfix(node_p node) {
    // node has pointer to parent, but parent has no pointer to node

    // red node does not affect black height
    if(node_color(node) == red) {return;}

    // black node's child, set to black to keep black height
    // (node can only have 1 child here, because rleft_most())
    if(node->left || node->right) {
      if(node->left) {node->left->color = black;}
      if(node->right) {node->right->color = black;}
      return;
    }

    // root has to parent
    if(!node->parent) {return;}

    // otherwise, we delete a black node that have no child,
    // to fix we need to jump up.
    // it's sib must exist to keep balance, sib() can't be used
    // because parent does not know node now: one child + one nullptr.
    node_p si = node->parent->left;
    if(!si) {si = node->parent->right;}

    delfixcases(si);
  }

  void delfix_redparent(node_p si) {
    // case 6-9: parent red
    // copy func pointer and others
    typedef void (RBTree::*rot_func)(link);
    rot_func rleft = &RBTree::left_rotate;
    rot_func rright = &RBTree::right_rotate;
    node_p si_l = si->left;
    node_p si_r = si->right;
    if(si == si->parent->left) {
      std::swap(rleft, rright);
      std::swap(si_l, si_r);
    }
    auto parent = si->parent;

    // parent red, sib black
    // case 6: both child black
    if (node_color(si_l) == black && node_color(si_r) == black) {
      (this->*rleft)(get_link(parent));
    }

    // 7: left red, right black
    else if (node_color(si_l) == red && node_color(si_r) == black) {
      parent->color = black;
      (this->*rright)(get_link(si));
      (this->*rleft)(get_link(parent));
    }

    // 8: left black, right red
    else if (node_color(si_l) == black && node_color(si_r) == red) {
      (this->*rleft)(get_link(parent));
    }

    // 9: both red
    else if (node_color(si_l) == red && node_color(si_r) == red) {
      parent->color = black;
      (this->*rright)(get_link(si));
      (this->*rleft)(get_link(parent));
    }

  }

  void delfixcases(node_p si) {
    // parent, sib, sib's child make 9 color combinations together.
    // (assuming node to delete is a left child)

    // rotate func pointer that takes link as input
    typedef void (RBTree::*rot_func)(link);
    rot_func rleft = &RBTree::left_rotate;
    rot_func rright = &RBTree::right_rotate;

    node_p si_l = si->left;
    node_p si_r = si->right;

    // if sib is left, make them right.
    if(si == si->parent->left) {
      std::swap(rleft, rright);
      std::swap(si_l, si_r);
    }

    auto parent = si->parent;

    // Cases
    // 1-5: parent black
    if(node_color(parent) == black) {

      // 1-4: sib black
      if(node_color(si) == black) {

        // 1: child both black
        if(node_color(si_l) == black && node_color(si_r) == black) {
          si->color = red;
          if(parent->parent) {delfixcases(sib(parent));}
        }
        // 2: left red, right black
        else if(node_color(si_l) == red && node_color(si_r) == black) {
          si_l->color = black;
          (this->*rright)(get_link(si));
          (this->*rleft)(get_link(parent));
        }
        // 3: left black, right red
        else if(node_color(si_l) == black && node_color(si_r) == red) {
          si_r->color = black;
          (this->*rleft)(get_link(parent));
        }
        // 4: both red
        // else if(node_color(si_l) == red && node_color(si_r) == red) {
        else {
          si_l->color = black;
          (this->*rright)(get_link(si));
          (this->*rleft)(get_link(parent));
        }
      }
      // 5: sib red
      else {
        parent->color = red;
        si->color = black;
        (this->*rleft)(get_link(parent));
        delfix_redparent(si_l);
      }
    }

    // 6-9: parent red
    else {delfix_redparent(si);}
  }
};


void test_insert(RBTree &tree) {
  for (int i = 0;i < 1000; ++i) {
   int a = std::rand() % 400;
    tree.insert(a);
    tree.check();

  }
}


void test_delete(RBTree &tree) {
  for (int i = 0;i < 1000; ++i) {
    auto tmp = rand() % 400;
    tree.del(tmp);
    tree.check();
  }
}


TEST(RBTreeTest, SomeTest) {
  auto a = RBTree();
  test_insert(a);
  test_delete(a);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
