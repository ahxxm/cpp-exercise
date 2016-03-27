#include "gtest/gtest.h"
#include <string>
#include <new>


void test() {
  // allocate large enough raw, untyped memory to hold object
  // run appropriate constructor
  // return pointer
  std::string *sp = new std::string("str");
  std::string *arr = new std::string[10];

  delete sp; // destroy pointer and free pointed memory
  delete [] arr; // destroy 10 strings and free memory

};

class Foo {
  // new and delete operator does not change
  // new and delete expression

  // called when new a Foo object
  // must return void*
  void *operator new(std::size_t, void *) noexcept;

  // called when delete a Foo pointer
  // must return void
  void operator delete(void *, std::nothrow_t &) noexcept;
};


TEST(MemAllocationTest, SomeTest) {
  test();
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
