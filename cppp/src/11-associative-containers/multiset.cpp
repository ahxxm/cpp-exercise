#include <map>
#include <set>
#include <vector>
#include "gtest/gtest.h"


TEST(SetTest, SomeTest) {
  std::vector<int> ivec;
  for (int i = 0; i != 10; ++i) {
    ivec.push_back(i);
    ivec.push_back(i);
  }


  // multiset accepts same value.. in a set?!
  std::set<int> iset(ivec.begin(), ivec.end());
  std::multiset<int> miset(ivec.cbegin(), ivec.cend());
  unsigned int vec_size = 20;
  unsigned int set_size = 10;
  unsigned int miset_size = vec_size;
  EXPECT_EQ(ivec.size(), vec_size);
  EXPECT_EQ(iset.size(), set_size);
  EXPECT_EQ(miset.size(), miset_size);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
