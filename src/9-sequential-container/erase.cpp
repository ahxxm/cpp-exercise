#include "gtest/gtest.h"
#include <list>


TEST(ListEraseTest, SomeTest) {
  std::list<int> lst = {0, 1, 2, 3, 4, 5, 6, 7, 8};
  auto it = lst.begin();

  while (it != lst.end()) {
    if ( * it % 2) {
      int previous_val = *it;
      it = lst.erase(it);
      int new_val = *it;
      EXPECT_EQ(previous_val + 1, new_val);
    } else {
      ++it;
    }
  }

  // removed from lst
  auto after_len = lst.size();
  EXPECT_EQ(after_len, 5);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
