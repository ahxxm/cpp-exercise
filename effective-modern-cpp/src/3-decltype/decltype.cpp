#include <iostream>
#include <utility>
#include "gtest/gtest.h"
#include <vector>



void decl() {
  int w = 2;
  std::cout << &w << std::endl;

  // decltype(auto) k = w; // c++14 extension

}

// trail type is not required in C++14
template<typename Container, typename Index>
auto authAndAccess(Container &&c, Index i)->decltype(std::forward<Container>(c)[i]) {
  // authenticate();
  // FIXME: forward in item 25
  return std::forward<Container>(c)[i];
};


TEST(MoreClassExerciseTest, SomeTest) {
  decl();
  std::vector<int> ve = {1, 2, 3, 4};
  auto k = authAndAccess(ve, 1);
  EXPECT_EQ(k, 2);


}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
