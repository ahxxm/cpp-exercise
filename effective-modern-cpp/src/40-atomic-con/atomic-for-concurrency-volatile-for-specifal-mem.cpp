#include <iostream>
#include "gtest/gtest.h"


void atom() {
  // instantiation is guaranteed to to atomic

  std::atomic<int> ai(0);

  // all operation are atomic
  ai = 10;

  // LIMITED to read operation, between read and <<
  // the value could be changed.
  // cout uses pass-by-value, no affect though.
  std::cout << ai << std::endl;
  ++ai;
  --ai;
}

void vol() {
  // volatile does not guarantee anything
  volatile int vi {1};
  vi = 10;
  std::cout << vi << std::endl;
  ++vi;
  --vi;
}


TEST(AtomicVolatileTest, SomeTest) {
  atom();
  vol();
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
