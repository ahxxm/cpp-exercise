#include <map>
#include <string>
#include <vector>
#include "gtest/gtest.h"


using mm = std::map<int, int>;


class Solution {
public:
  int removeDuplicates(std::vector<int>& nums) {
    // dups that more than 2
    int dups = 0;

    for (auto i: nums) {
      if (fc(i) > 2) {
        dups += 1;
      }
    }
    return nums.size() - dups;

  }
private:
  mm m;

  // means find and count
  int fc(const int &i) {
    if (m.find(i) != m.end()) {
      m[i] += 1;
      return m[i];
    } else {
      m[i] = 1;
      return m[i];
    }
  }


};

TEST(RemoveDupsII, SomeTest) {
  std::vector<int> i = {1,1,1,2,2,3};
  auto a = Solution();
  EXPECT_EQ(a.removeDuplicates(i), 5);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
