#include <initializer_list>
#include <iostream>

#include "gtest/gtest.h"


struct Node {
  int value;
  Node *prev = nullptr;
  Node *next = nullptr;

  explicit Node(const int i) {
    value = i;
  }

};

// Double-linked list: hides Node in interface
// can be used as stack/queue
class LinkedList {
public:
  // constructor
  LinkedList() {
    root = nullptr;
    last = nullptr;
  };

  explicit LinkedList(const int &n) {
    root = new Node(n);
    last = root;
    size = 1;
  };

  explicit LinkedList(const std::initializer_list<int> &lst);

  ~LinkedList() {
    del(root);
  }

  void del(Node *node) {
    if (node) {
      if (node->next) {
        del(node->next);
      }
      delete node;
    }
  }

  int length() {
    return size;
  }

  LinkedList &push_back(const int &i) {
    auto node = new Node(i);
    if (size == 0) {
      size += 1;
      root = node;
      last = node;
      return *this;
    }

    // else make node last, link it with
    // previous last
    last->next = node;
    node->prev = last;
    last = node;
    size += 1;
    return *this;
  };

  auto pop() {
    if (size == 0) {
      return -1;
    }

    auto k = last->value;
    last = last->prev;
    size -= 1;

    if (last) {
      // in case root is pop-ed,
      // then last is already nullptr
      delete last->next;
      last->next = nullptr;
    }

    return k;
  };

  // can be used as dequeue
  auto pop_first() {
    if (size == 0) {
      return -1;
    }

    auto k = root->value;
    root = root->next;
    delete root->prev;
    root->prev = nullptr;
    size -= 1;
    return k;
  }

  // TODO: circular detection
  auto search(const int &) = delete;
  bool is_circular();

  bool is_empty() {
    return size == 0;
  }

  void display() {
    auto iter = root;
    while (iter) {
      std::cout << iter->value << " ";
      iter = iter->next;
    };

    std::cout << std::endl;
  };

private:
  // 1st/last element
  Node *root;
  Node *last;

  int size = 0;
};

LinkedList::LinkedList(const std::initializer_list<int> &lst) {
  for (const auto v : lst) {
    this->push_back(v);
  }
};



TEST(LinkedListTest, SomeTest) {
  auto a = LinkedList();
  auto z = a.pop();
  EXPECT_EQ(z, -1);
  EXPECT_EQ(a.is_empty(), true);

  a.push_back(4);
  a.push_back(4);
  EXPECT_EQ(a.length(), 2);
  EXPECT_EQ(a.is_empty(), false);
  a.display();

  auto b = a.pop();
  EXPECT_EQ(b, 4);
  EXPECT_EQ(a.length(), 1);


  auto c = LinkedList(3);
  EXPECT_EQ(c.length(), 1);
  c.push_back(2);
  EXPECT_EQ(c.length(), 2);
  auto d = c.pop_first();
  EXPECT_EQ(d, 3);
  EXPECT_EQ(c.length(), 1);

  auto e = LinkedList({1, 2, 3, 4});
  EXPECT_EQ(e.length(), 4);
  auto f = e.pop_first();
  EXPECT_EQ(f, 1);
  EXPECT_EQ(e.length(), 3);

}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
