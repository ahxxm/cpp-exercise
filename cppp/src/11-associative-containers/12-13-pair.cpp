#include "gtest/gtest.h"
#include <utility>
#include <vector>
#include <string>

// 12:
// sequence of strings ints into vector<pair>
std::vector<std::pair<std::string, int>> convert_string_int_into_pair(const std::vector<std::string> &st, const std::vector<int> it) {
  std::vector<std::pair<std::string, int>> pa;

  if (st.size() != it.size()) {
    return pa;
  }

  for (unsigned long i = 0; i != st.size(); ++i) {
    // 13: 3 ways define a pair
    // std::pair<std::string, int> p = {st[i], it[i]};
    // std::pair<std::string, int> p {st[i], it[i]};
    std::pair<std::string, int> p;
    p.first = st[i];
    p.second = it[i];

    pa.push_back(p);
  }

  return pa;
}


TEST(PairTest, SomeTest) {
  std::vector<std::string> st = {"a", "b", "c"};
  std::vector<int> it = {1, 2, 3};
  std::vector<int> it_2 = {1, 2, 3, 4};
  auto p = convert_string_int_into_pair(st, it);
  auto p2 = convert_string_int_into_pair(st, it_2);
  EXPECT_EQ(p2.size(), 0);
  EXPECT_EQ(p[0].first, "a");
  EXPECT_EQ(p[0].second, 1);

}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}