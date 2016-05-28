#include <iostream>
#include "gtest/gtest.h"


// Advantages
// - name does not leak
// - strong type
// - forward declaration

// enum Yay; error
enum class Yay;



void scope() {
  // names in C++98-style enums belong to scope containing enum
  enum Color {black, white, red}; // then whole scope has black
  // auto white = false; // redeclared

  // scoped do not leak names
  enum class scoper {one, two, three};
  auto three = 3;
  auto c = scoper::one;
  std::cout << &three << std::endl;
  std::cout << &c << std::endl;

  // unscoped enumerators implicitly convert to integral type
  auto a = black;
  if (a < 233) {
    std::cout << "123" << std::endl;
  }

  // no matched operator for scoped
  // if (c < 123)

  // weird but it compiles
  if (static_cast<int>(c) < 233) {
    std::cout << "c" << std::endl;
  }
}


TEST(EnumTest, SomeTest) {
  scope();
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
