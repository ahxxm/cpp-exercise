#include "gtest/gtest.h"
#include <type_traits>

// std::move
template <typename T>
typename std::remove_reference<T>::type &&move(T&& t) {
  // http://thbecker.net/articles/rvalue_references/section_08.html
  // T&& accepts any type by reference collapse:
  // When foo is called on an lvalue of type A, then T resolves to A& and hence, by the reference collapsing rules above, the argument type effectively becomes A &.
  // When foo is called on an rvalue of type A, then T resolves to A, and hence the argument type becomes A &&.
  return static_cast<typename std::remove_reference<T>::type &&>(t);
};



TEST(MoveTest, SomeTest) {
  int i = 2;
  auto b = move(i);
  EXPECT_EQ(b, 2);

  auto c = move(2);
  EXPECT_EQ(c, 2);

}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
