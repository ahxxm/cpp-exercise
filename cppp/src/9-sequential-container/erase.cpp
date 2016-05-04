#include <list>
#include "gtest/gtest.h"


int erase_test() {
  std::list<int> lst1 = {0, 1, 2, 3, 4, 5, 6};

  // what if elem1 and elem2 are equal
  // what if they are both .end
  // A: nothing happends..
  auto elem1 = lst1.end();
  auto elem2 = lst1.end();
  lst1.erase(elem1, elem2);

  auto length = lst1.size();
  return length;
}

std::list<int> copy_array_into_list() {
  int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
  std::list<int> va = {std::begin(ia), std::end(ia)};
  return va;
}


TEST(ListEraseTest, SomeTest) {
  std::list<int> lst = {0, 1, 2, 3, 4, 5, 6, 7, 8};
  auto it = lst.begin();

  while (it != lst.end()) {
    if (*it % 2) {
      int previous_val = *it;
      it = lst.erase(it);
      int new_val = *it;
      // returns iterator to
      // the element just after the last removed one
      EXPECT_EQ(previous_val + 1, new_val);
    } else {
      ++it;
    }
  }

  // removed from lst
  auto after_len = lst.size();
  EXPECT_EQ(after_len, 5);

  // 9.25 erase test
  int length = erase_test();
  EXPECT_EQ(length, 7);

  // 9.26 array to list
  auto converted_lst = copy_array_into_list();
  EXPECT_EQ(converted_lst.size(), 11);
  // single iterator form of erase remove odd values
  // check `while` part above..

}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
