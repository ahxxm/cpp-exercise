#include <list>
#include <string>
#include <type_traits>
#include "gtest/gtest.h"


void prefer() {

  // using alias is easier to parse
  // typedef void (*FP)(int, const std::string &);
  // using FP2 = void (*)(int, const std::string &);

}


// using alias can be templatized
// template<typename T>
// using MyAllocator = std::list<T, MyAlloc<T>> ;


// C++14's std::remove_const_t
// same for: remove_reference_t, add_lvalue_reference_t
template<class T>
using remove_const_t = typename std::remove_const_t<T>;



TEST(AliasTest, SomeTest) {
  prefer();
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
