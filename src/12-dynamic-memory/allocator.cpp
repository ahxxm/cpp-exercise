#include "gtest/gtest.h"
#include <memory>
#include <iostream>


// decouple memory allocation from object construction
void allocator() {
  std::allocator<int> a;

  // raw, unconstructed memory to hold 10 int
  int *a1 = a.allocate(10);
  a1[2] = 233;
  std::cout << a1[2] << std::endl;

  // will point to one past the last constructed element
  // so type is int*
  auto q = a1;

  // default construct and value construct
  a.construct(q++);
  a.construct(q++, 42);

  // destroy memory: does not free it
  while (q != a1) {
    a.destroy(--q);
  }

  // return memory to system, 10 must be the same as size
  a.deallocate(q, 10);

  // FIXME: still prints 233
  std::cout << a1[2] << std::endl;

}

TEST(AllocatorTest, SomeTest) {
  allocator();
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
