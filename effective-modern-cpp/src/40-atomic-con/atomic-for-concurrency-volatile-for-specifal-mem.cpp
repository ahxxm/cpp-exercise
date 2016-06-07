#include <iostream>
#include "gtest/gtest.h"


void atom() {
  // instantiation is guaranteed to to atomic
  std::atomic<int> ai(0);

  // all operation are atomi
  ai = 10;
  std::cout << ai << std::endl;
  ++ai;
  --ai;


}

TEST(AtomicVolatileTest, SomeTest) {
  atom();
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
