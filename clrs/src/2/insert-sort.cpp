#include <vector>
#include "gtest/gtest.h"

template<typename T >
static void swap(std::vector<T> &elems, const int i, const int j) {
  T temp = elems[i];
  elems[i] = elems[j];
  elems[j] = temp;
}

template<typename T>
auto insertSort(std::vector<T> elems) {
  for(int i = 0;i < static_cast<int>(elems.size() - 1); i++) {
    for(int j = i + 1; j > 0 && (elems[j] < elems[j - 1]); j--) {
      swap(elems, j - 1, j);
    }
  }
  return elems;
}


TEST(InsertSortTest, SomeTest) {
  std::vector<int> ve {1, 4, 2, 5, 3};
  auto vc = insertSort(ve);
  std::vector<int> ve_result {1, 2, 3, 4, 5};
  EXPECT_EQ(vc, ve_result);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
