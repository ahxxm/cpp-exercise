#include "gtest/gtest.h"
#include <map>
#include <vector>
#include <utility>


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

  // add new element to map
  oo.insert({2, va});
  oo.insert(std::make_pair(3, va));
  auto result = oo.insert(miv::value_type(4, va));
  EXPECT_EQ(oo[2][0], 1);
  EXPECT_EQ(oo[3][0], 1);
  EXPECT_EQ(oo[4][0], 1);

  // .first is an iterator to the element
  // .second is bool
  EXPECT_EQ(result.second, true);
  EXPECT_EQ(result.first->first, 4);
  EXPECT_EQ(result.first->second[0], 1);


}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
