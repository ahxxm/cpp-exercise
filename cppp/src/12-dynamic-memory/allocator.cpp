#include <memory>
#include <iostream>
#include <vector>
#include "gtest/gtest.h"


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

}

void allocator_construct_method() {
  std::vector<int> vi = {1, 2, 3, 4, 5};
  std::allocator<int> alloc;

  // allocate twice size
  auto twice = vi.size() * 2;
  auto p = alloc.allocate(twice);

  // copy vi into first half
  auto q = std::uninitialized_copy(vi.begin(), vi.end(), p);

  // remaining half to initialize with value 42
  std::uninitialized_fill_n(q, vi.size(), 42);
  alloc.deallocate(p, twice);
}



TEST(AllocatorTest, SomeTest) {
  allocator();
  allocator_construct_method();
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
