#include <utility>
#include <vector>
#include <string>
#include "gtest/gtest.h"

// 12:
// sequence of strings ints into vector<pair>
typedef std::vector<std::pair<std::string, int>> vps;
vps convert_string_int_into_pair(const std::vector<std::string> &st, const std::vector<int> it) {
  vps pa;

  if (st.size() != it.size()) {
    return pa;
  }

  for (uint64_t i = 0; i != st.size(); ++i) {
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

  unsigned int p2_size = 0;
  int p_second = 1;
  EXPECT_EQ(p2.size(), p2_size);
  EXPECT_EQ(p[0].first, "a");
  EXPECT_EQ(p[0].second, p_second);

}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
