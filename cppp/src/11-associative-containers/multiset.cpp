#include "gtest/gtest.h"
#include <map>
#include <set>
#include <vector>


TEST(SetTest, SomeTest) {
  std::vector<int> ivec;
  for (int i = 0;i != 10; ++i) {
    ivec.push_back(i);
    ivec.push_back(i);
  }


  // multiset accepts same value.. in a set?!
  std::set<int> iset(ivec.begin(), ivec.end());
  std::multiset<int> miset(ivec.cbegin(), ivec.cend());
  EXPECT_EQ(ivec.size(), 20);
  EXPECT_EQ(iset.size(), 10);
  EXPECT_EQ(miset.size(), 20);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
