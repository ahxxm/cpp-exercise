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

TEST(MapIteratorTest, SomeTest) {
  type_identify();

  // 16: use map iterator to assign value to element
  typedef std::map<int, std::vector<int>> miv;
  std::vector<int> va = {1, 2, 3};
  std::vector<int> vb = {4, 5, 6};
  miv oo;
  oo[1] = va;
  oo.begin()->second = vb;
  EXPECT_EQ((oo.begin()->second)[0], 4);

}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
