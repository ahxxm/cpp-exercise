#include <memory>
#include <iostream>
#include <vector>
#include "gtest/gtest.h"

/* from stl
  template<typename _Up, typename... _Args>
	void
	construct(_Up* __p, _Args&&... __args)
	noexcept(std::is_nothrow_constructible<_Up, _Args...>::value)
	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }

  template<typename _Up>
	void
	destroy(_Up* __p)
	noexcept(std::is_nothrow_destructible<_Up>::value)
	{ __p->~_Up(); }
 */

// decouple memory allocation from object construction
void allocator() {
  std::allocator<int> a;

  // raw, unconstructed memory to hold 10 int
  int *a1 = a.allocate(10);
  a1[2] = 233;
  std::cout << a1[2] << std::endl;

  // since c++20, use construct_at and destroy_n
  auto q = a1;
  std::construct_at(q++, 0);
  std::construct_at(q++, 42);
  std::destroy_n(a1, 3); // previous a1[2]

  // return memory to system, 10 must be the same as size
  a.deallocate(a1, 10); // calls destructor(::operator delete?)
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
