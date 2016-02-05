#include "gtest/gtest.h"
#include <string>

// 43: takes: string s, old, new
// replace all old with new in s, using iterator, insert and erase.
void erase_ins(std::string &st, const std::string &old, const std::string &newVal) {
  auto old_size = old.size();
  for (auto iter = st.begin();iter <= st.end() - old_size; ++iter) {
    std::string cur_string = std::string(iter, iter + old_size);
    if (cur_string == old) {
      // erase get pointer
      iter = st.erase(iter, iter + old_size);

      // insert after pointer
      iter = st.insert(iter, newVal.begin(), newVal.end());

      iter += old_size;
    } else {
      ++iter;
    }
  }
}


TEST(StringReplaceTest, SomeTest) {
  std::string st = "thintho";
  std::string old = "th";
  std::string newVal = "t";

  erase_ins(st, old, newVal);
  EXPECT_EQ(st, "tinto");
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
