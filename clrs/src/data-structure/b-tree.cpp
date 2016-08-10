#include <cstdlib>
#include <utility>
#include <vector>
#include "gtest/gtest.h"

// TODO: define degree first.. confusing

// B-tree of order 4 is a 2-3-4 tree, or 2-4 tree
// For a B-tree of degree(D), each non-root node contains
// (D-1) to (2D-1) keys, including D-1 and 2D-1:
//   D >= 2

//   Each node can hold up to 2t children.
//   Root has at least 2 children, if it has.

//   All leaves(node that has no children) are on same level.

//   Insert a key into node that contains 2D, will pop its mid
//   to parent, and split node into 2 nodes, each has D keys.

//   Increase height only by split root.

//   Delete key from node of D is ...? TODO


struct Node;
struct Key;
using key_p = Key*;
using node_p = Node*;

struct Key {
  int value;
  key_p next, prev;

  Key(int val) {
    value = std::move(val);
    next = nullptr;
    prev = nullptr;
  }
};


struct Node {
  // Node holds keys/childs as a vector
  // manage by index
  std::vector<key_p> keys;
  std::vector<node_p> childs;

  // to be compared with degree
  // TODO: generate from keys.size()?
  int size;

  // leaf: does not have child
  bool leaf;

  Node() {
    size = 0;
    leaf = true;
  }
};


class BTree {
public:
  // by default a 2-3 tree
  BTree() {
    root = new Node();
    degree = 2;
    disk();
  };

  BTree(int _degree) {
    root = new Node();
    degree = std::move(_degree);
    disk();
  }

  auto disk_operation() {
    return count;
  }

  key_p search(int val) {
    return search(root, val);
  };

  void check() {


  }

  // TODO:
  ~BTree() = default;

  void insert(int val);
  void del(int val);


private:
  node_p root;
  int degree;

  // records disk operation
  int count = 0;
  void disk() {
    count += 1;
  }

  // TODO:
  void check(node_p node) {
    if(!node) {return ;}
  }



  key_p search(node_p node, int val) {

    // search for child(might have val)
    int index = 0;
    while(index <= node->size && val > node->keys[index]->value) {
      index += 1;
    }

    // in case key->value == val, or reach leaf but no result
    if(index <= node->size && val == node->keys[index]->value) {
      return node->keys[index];
    } else if (node->leaf) {
      return nullptr;
    }

    // else dive in next level
    disk();
    return search(node->childs[index], val);
  }


  void split_child(node_p node, int i) {
    // child[i] is full: child[i]->size == 2d - 1
    // pop its median to node

    auto sib = new Node();
    auto child = node->childs[i];

    // child[i]'s neighbor will be on same level
    // of it, and own's right half of values.
    // it's child cound after split = (2d - 1 - 1) / 2
    sib->leaf = child->leaf;
    sib->size = degree - 1;

    // move keys to sib
    for(int i = 0; i < degree; ++i) {
      auto offset = i + degree;
      sib->keys.emplace_back(child->keys[offset]);
    }

    // if child is not leaf, it has childs, copy
    // right half(d-1) to new node, set left half's size.
    if(!child->leaf) {
      for(int i = 0; i < degree; ++i) {
        auto offset = i + degree;
        sib->childs.emplace_back(child->childs[offset]);
      }
    }
    child->size = degree - 1;

    // sib will be node's childs[i+1]
    // child[d] will be node->keys[i]
    // child->keys will shrink to size of degree-1
    node->childs.insert(node->childs.begin() + i + 1, sib);
    node->keys.insert(node->keys.begin() + i, child->keys[degree - 1]);

    // TODO: remaining values in child->keys
    // TODO: assert key value >

    node->size += 1;

    // disk write for node, child and sib
    disk();
    disk();
    disk();
  }

};


/*
void test_insert(BTree &tree) {
  for (int i = 0;i < 1000; ++i) {
    auto tmp = std::rand() % 400;
    tree.insert(tmp);
    tree.check();
  }
}
*/


TEST(BTreeTest, SomeTest) {
  // auto tree = BTree();
  // test_insert(tree);
  EXPECT_TRUE(true);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
