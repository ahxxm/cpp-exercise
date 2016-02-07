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
      // returns void
      st.insert(iter, newVal.begin(), newVal.end());

      iter += old_size;
    } else {
      ++iter;
    }
  }
}

// 44: rewrite with replace
void rep(std::string &st, const std::string &old, const std::string &newVal) {
  auto old_size = old.size();

  for (unsigned long i = 0; i <= st.size() - old_size; ++i) {
    std::string cur_string = std::string(st.begin() + i, st.begin() + i + old_size);

    if (cur_string == old) {
      // i: start index
      // old_size: length of substr to be replaced
      // finally: increment i to character one pass last
      // element of newVal
      st.replace(i, old_size, newVal);
      i += old_size;
    }
  }
}


TEST(StringReplaceTest, SomeTest) {
  std::string st = "thintho";
  std::string old = "th";
  std::string newVal = "t";

  erase_ins(st, old, newVal);
  EXPECT_EQ(st, "tinto");

  std::string st2 = "thintho";
  rep(st2, old, newVal);
  EXPECT_EQ(st2, "tinto");
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
