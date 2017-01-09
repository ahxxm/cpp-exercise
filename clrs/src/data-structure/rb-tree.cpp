#include "gtest/gtest.h"
#include "rb-tree.h"


void test_insert(RBTree &tree) {
  for (int i = 0; i < 1000; ++i) {
    int a = std::rand() % 400;
    tree.insert(a);
    tree.check();
  }
}


void test_delete(RBTree &tree) {
  for (int i = 0; i < 1000; ++i) {
    auto tmp = std::rand() % 400;
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
