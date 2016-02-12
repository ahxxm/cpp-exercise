#include "gtest/gtest.h"
#include <map>
#include <vector>


// 15:
void type_identify() {
  typedef std::map<int, std::vector<int>> miv;

  miv::mapped_type j; // std::vector<int>
  j.size();

  miv::key_type k; // int
  std::cout << sizeof(k) << std::endl;

  miv::value_type i;
  // i.first; // std::pair

}

TEST(MoreClassExerciseTest, SomeTest) {
  type_identify();

  // 16: use map iterator to assign value to element
  typedef std::map<int, std::vector<int>> miv;
  std::vector<int> va = {1, 2, 3};
  miv oo;
  oo[1] = va;
  EXPECT_EQ((oo.begin()->second)[0], 1);

}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
