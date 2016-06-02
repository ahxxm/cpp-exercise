#include <utility>
#include "gtest/gtest.h"


// universal ref: include type deduction
template<typename T>
void f(T &&) {};

int v1 = 1;
auto &&v = v1;

// rvalue ref: no type deduction
void f(int &&) {};

int &&vv = 1;

// T&& is universal ref, <T>&& is rvalue
template<typename T>
void ff(std::vector<T> &&) {};


TEST(RefTest, SomeTest) {
  std::vector<int> v {};

  // no matching function
  // ff(v);

  // this works
  ff(std::move(v));


}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
