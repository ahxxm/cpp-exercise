#include <list>
#include <string>
#include "gtest/gtest.h"


void prefer() {

  // using alias is easier to parse
  // typedef void (*FP)(int, const std::string &);
  // using FP2 = void (*)(int, const std::string &);

}


// using alias can be templatized
// template<typename T>
// using MyAllocator = std::list<T, MyAlloc<T>> ;
// FIXME: implement custom allocator MyAlloc



TEST(AliasTest, SomeTest) {
  prefer();
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
