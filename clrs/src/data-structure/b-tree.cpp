#include <iostream>
#include <cassert>
#include <cstdlib>
#include <utility>
#include <vector>
#include "gtest/gtest.h"


// For a B-tree of degree(D), each non-root node contains
// (D-1) to (2D-1) keys, including D-1 and 2D-1:
//   D >= 2

//   Each node can hold up to 2t children.
//   Root has at least 2 children, if it has.

//   All leaves(node that has no children) are on same level.

//   Insert a key into node that contains 2D, will pop its mid
//   to parent, and split node into 2 nodes, each has D keys.

//   Increase height only by split root.

//   Delete key from node of D is ...?
//   https://github.com/algorithm-ninja/cpp-btree/blob/master/btree.h#L1861


struct Node;
using node_p = Node*;

struct Node {
  // Node holds keys/childs as a vector
  // manage by index
  std::vector<int> keys;
  std::vector<node_p> childs;

  // should be equal to keys.size()
  // keep it separate for accounting
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
  // search result, if no result then <nullptr, -1>
  using result_t = std::pair<node_p, int>;

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

  auto search(int val) {
    return search(root, val);
  };

  void insert(int val) {
    // root is always initialized in ctor
    auto iter = root;
    std::cout << "insert: " << val<< std::endl;

    if(iter->size < 2 * degree - 1) {
      insert_non_full(iter, val);
      return;
    }

    // else create new root r
    auto r = new Node();
    root = r;
    r->leaf = false;
    r->size = 0;
    r->childs.emplace_back(iter);
    split_child(r, 0);
    insert_non_full(r, val);
  };


  void check() {check(root);};

  void del(int val) {
    std::cout << "del: " << val << std::endl;

    auto search_r = search(val);
    if ((!search_r.first) || search_r.second == -1) {return;}

    // 1. if leaf just delete this key
    auto node = search_r.first;
    auto i = search_r.second;
    if(node->leaf) {
      node->keys.erase(node->keys.begin() + i);
      node->size -= 1;
      // FIXME: fix when node needs combination!
      return;
    }

    // TODO:
    // 2. else for internal node x and key k
    // 2a: if child y precedes(left to) k has >= t keys,
    // find predecessor k', recusively delete k', replace k by k'.

    // 2b: if child z follows(right to)k has >= t keys,
    // find successor k', recusively delete k', replace k by k'.

    // 2c: y and z both t-1 keys, merge k and z into y.
    // so that x loses k and pointer to z, and y contains 2t-1 keys.
    // free z and recusively delete k from y. (???)

    // 3.

  };

  // TODO:
  ~BTree() = default;



private:
  node_p root;
  int degree;

  // records disk operation
  int count = 0;
  void disk() {
    count += 1;
  }

  void insert_non_full(node_p node, int val) {
    // backwardly compare
    auto i = node->size - 1;
    if(node->leaf) {
      // insert a immediately-replaced-value for new key
      node->keys.emplace_back(-1);
      while(i >= 0 && val < node->keys[i]) {
        node->keys[i + 1] = node->keys[i];
        --i;
      }

      if(node->keys.empty()) {
        node->keys.emplace_back(val);
      } else {
        node->keys[i + 1] = val;
      }
      node->size += 1;
      return;
    }

    // else not leaf
    while(i >= 0 && val < node->keys[i]) {
      --i;
    }

    // see if child full, needs split
    if(node->childs[i + 1] && node->childs[i + 1]->size == 2 * degree - 1) {
      split_child(node, i + 1);

      // after split, check which i have mid key
      if(node->keys[i + 1] < val) {++i;}
    }
    insert_non_full(node->childs[i + 1], val);
  }

  result_t search(node_p node, int val) {
    // search for child(might have val)
    int index = 0;
    while(index <= node->size && index < static_cast<int>(node->keys.size()) && val > node->keys[index]) {
      index += 1;
    }

    // in case key->value == val, or reach leaf but no result
    if(index <= node->size && val == node->keys[index]) {
      return std::make_pair(node, index);
    } else if (node->leaf) {
      return std::make_pair(nullptr, -1);
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
    sib->keys = {std::make_move_iterator(child->keys.begin() + degree),
                 std::make_move_iterator(child->keys.end())};
    child->keys.erase(child->keys.begin() + degree - 1, child->keys.end());

    // if child is not leaf, it has childs, copy
    // right half(d-1) to new node, set left half's size.
    if(!child->leaf) {
      sib->childs = {std::make_move_iterator(child->childs.begin() + degree),
                     std::make_move_iterator(child->childs.end())};
      child->childs.erase(child->childs.begin() + degree, child->childs.end());
    }
    child->size = degree - 1;

    // sib will be node's childs[i+1]
    // child[d] will be node->keys[i]
    // child->keys will shrink to size of degree-1
    node->childs.insert(node->childs.begin() + i + 1, sib);
    node->keys.insert(node->keys.begin() + i, child->keys[degree - 1]);
    node->size += 1;

    // disk write for node, child and sib
    disk();
    disk();
    disk();
  }


  void check_keys(std::vector<int> keys) {
    if(keys.size() <= 1) {return;}

    auto tmp = keys[0];
    int len = keys.size();
    for (int i = 1; i < len; ++i) {
      if(tmp > keys[i]) {
        std::cout << "keys unordered error: " << tmp << " > " << keys[i] << std::endl;
      }
      assert(tmp <= keys[i]);

      tmp = keys[i];
    }
  }

  void check(node_p node) {
    if(!node) {return ;}

    // keys should be ordered, note that non-null nodes have at least 1 key
    check_keys(node->keys);

    // all non-root node follow degree: d-1 <= size(key.size()) <= 2d -1
    if(node != root) {
      assert(static_cast<unsigned long>(degree - 1) <= node->keys.size() &&
             static_cast<unsigned long>(2 * degree - 1) >= node->keys.size());
    }

    assert(node->size == static_cast<int>(node->keys.size()));

    // leaf node has no childs,
    if(node->leaf) {
      assert(node->childs.size() == 0);
    } else {
      // childs 1 more than keys(left/right child), if not leaf
      assert(node->keys.size() + 1 == node->childs.size());
      for(auto c: node->childs) {check(c);}
    }
  }

};


void test_insert(BTree &tree) {
  for (int i = 0;i < 40; ++i) {
    auto tmp = std::rand() % 2345;
    tree.insert(tmp);
    tree.check();
  }
}

void test_delete(BTree &tree) {
  for (int i = 0;i < 400; ++i) {
    auto tmp = std::rand() % 2345;
    tree.del(tmp);
    tree.check();
  }
}


TEST(BTreeTest, SomeTest) {
  auto tree = BTree(5);
  test_insert(tree);
  std::cout << tree.disk_operation() << std::endl;

  // test_delete(tree);
  // std::cout << tree.disk_operation() << std::endl;

  auto r = tree.search(-10);
  EXPECT_FALSE(r.first);
  EXPECT_EQ(r.second, -1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
