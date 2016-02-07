#include "gtest/gtest.h"
#include <vector>



TEST(ContainerMemberTypeTest, SomeTest) {

  // type of these objects
  std::vector<int> v1;
  const std::vector<int> v2;

  // 1 is iterator, 2 3 4 are const iterator
  auto it1 = v1.begin();
  auto it2 = v2.begin();
  auto it3 = v1.cbegin();
  auto it4 = v2.cbegin();

  EXPECT_EQ(it1, v1.end());
  EXPECT_EQ(it2, v2.cend());
  EXPECT_EQ(it3, v1.cend());
  EXPECT_EQ(it4, v2.end());
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
