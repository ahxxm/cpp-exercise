#include "gtest/gtest.h"

// TODO: ctor, sort, merge, print
// ctor: from last leaf( floor(n/2) ) down to 1, max-heapify(A, i, n)
// max-heapify: exchange i with smaller child until no smaller one
// sort: exchange root with last leaf, extract root(to result), max-heapify(A, 0, n-1)

// priority queue: increase/decrease key, insert, extract-min/max, delete
// inc/dec, exchange with parent/child until reasonable
// insert: to last leaf, and use inc


TEST(HeapTest, SomeTest) {
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
