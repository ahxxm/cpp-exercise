#include <vector>
#include "gtest/gtest.h"

template<typename T>
static void swap(T &elems, const int i, const int j) {
  auto temp = elems[i];
  elems[i] = elems[j];
  elems[j] = temp;
}

template<typename T>
auto insertSort(T elems) {
  for(int i = 0;i < static_cast<int>(elems.size() - 1); i++) {
    for(int j = i + 1; j > 0 && (elems[j] < elems[j - 1]); j--) {
      swap(elems, j - 1, j);
    }
  }
  return elems;
}

// 1-3 linear search
template<typename T>
auto linearSearch(std::vector<T>vec, const T &target) {
  for (int i = 0; i < static_cast<int>(vec.size()); ++i) {
    if (vec[i] == target) {
      return i;
    }
  }
  return -1;
}


TEST(InsertSortTest, SomeTest) {
  std::vector<int> ve {1, 4, 2, 5, 3};
  auto vc = insertSort(ve);
  std::vector<int> ve_result {1, 2, 3, 4, 5};

  std::vector<int> ve_short {1, 4, 2, 5, 3};
  EXPECT_EQ(vc, ve_result);
  EXPECT_EQ(linearSearch(ve_short, 1), 0);
  EXPECT_EQ(linearSearch(ve_short, 100), -1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
