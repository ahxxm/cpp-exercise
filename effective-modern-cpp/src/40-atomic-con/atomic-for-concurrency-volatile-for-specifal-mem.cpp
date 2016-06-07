#include <atomic>
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

  // atomic object can't be copied, for good reason:
  // in order to be atomic, compiler needs to read ai
  // and write i, both are atomic, failed.
  // auto i = ai;
}

void vol() {
  // volatile does not guarantee anything
  volatile int vi {1};
  vi = 10;
  std::cout << vi << std::endl;
  ++vi;
  --vi;

  // volatile is used to tell compiler
  // special memory is used, usually memory-mapped I/O:
  // display, printer..
  auto y = vi;
  y = vi;
  std::cout << &y<< std::endl;

}

void sequence() {

  // default atomic sequence consistency:
  // no code precedes a write of std::atomic may
  // be executed before it
  std::atomic<bool> flag(false);
  auto i = 42;
  flag = true;

  // i is assured to be 42
  std::cout << i << std::endl;
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
