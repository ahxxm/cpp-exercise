#include "gtest/gtest.h"
#include <vector>

/*

  a circle of stations, each offer gas[i] amount
  gas cost to next station if cost[i]
  unique solution(station index) or -1
 */


class Solution {
public:
  int canCompleteCircuit(std::vector<int> &gas, std::vector<int> &cost) {
    int k = gas.size();
    int left = 0;
    std::vector<int> diff(k, 0);
    for(int i = 0;i < k; ++i) {
      diff[i] = gas[i] - cost[i];
      left += diff[i];
    }

    // all cost > gas
    if(left < 0) {
      return -1;
    }

    int sum = 0, start = 0;
    for(int j = 0; j < k; ++j) {
      sum += diff[j];
      if(sum < 0) {
        start = j + 1;
        sum = 0;
      }
    }

    return start;
  }
};


TEST(GasStationTest, SomeTest) {
  std::vector<int> gas {5};
  std::vector<int> cost {4};
  auto a = Solution();
  std::cout << a.canCompleteCircuit(gas, cost) << std::endl;
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
