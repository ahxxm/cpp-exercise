#include <memory>
#include <utility>
#include "gtest/gtest.h"

class Widget {};

// make_unique join in C++14
// simple one
/*
template <typename T, typename... Ts>
std::unique_ptr<T> make_unique(Ts&&... params) {
  return std::unique_ptr<T>(new T(std::forward<Ts>(params)...));
  };
*/

int auto_make() {
  // make avoids duplication
  // exception-safe: leak between new and cast
  // performace: allocate object+control-block once
  auto upw1 {std::make_unique<Widget>()};
  std::cout << &upw1 << std::endl;

  // forwards paren, size 10 of value 20
  // brace can't be forwarded perfectly
  auto puv = std::make_unique<std::vector<int>> (10, 20);
  return static_cast<int>(puv->size());
}


TEST(MakePtrTest, SomeTest) {
  EXPECT_EQ(auto_make(), 10);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
