#include <type_traits>
#include <utility>
#include "gtest/gtest.h"

// std::move casts into rvalue,
// std::forward sometimes casts into rvalue: when arg is initialized with rvalud

// close to STL ipml
template<typename T>
typename std::remove_reference<T>::type&& move(T &&param) {
  using Return_T = typename std::remove_reference<T>::type&&;
  return static_cast<Return_T>(param);
};


TEST(MoveForwardTest, SomeTest) {
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
