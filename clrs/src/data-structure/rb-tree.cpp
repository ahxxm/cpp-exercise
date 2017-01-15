#include "gtest/gtest.h"
#include "rb-tree.h"


void test_insert(RBTree &tree, int k) {
  for (int i = 0; i < k; ++i) {
    int a = std::rand() % 400;
    tree.insert(a);
    tree.check();
  }
}

void test_insert(RBTree &tree) {
  for (int i = 0; i < 1000; ++i) {
    tree.insert(i);
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
  int rand_count = 1000;
  test_insert(a, rand_count);
  test_delete(a);

  auto b = RBTree();
  test_insert(b);
  EXPECT_EQ(b.getSize(), 1000);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
