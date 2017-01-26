#include <algorithm>
#include "gtest/gtest.h"


int partition(int *arr, const int left, const int right) {
  const int mid = left + (right - left) / 2;
  const int pivot = arr[mid];
  std::swap(arr[mid], arr[left]);

  auto i = left + 1;
  auto j = right;
  while (i <= j) {
    while (i <= j && arr[i] <= pivot) {
      ++i;
    }

    while (i <= j && arr[j] > pivot) {
      --j;
    }

    if (i < j) {
      std::swap(arr[i], arr[j]);
    }
  }
  std::swap(arr[i - 1], arr[left]);
  return i - 1;
}

void quicksort(int *arr, const int left, const int right) {
  if (left >= right) {
    return;
  }
  int part = partition(arr, left, right);
  quicksort(arr, left, part - 1);
  quicksort(arr, part + 1, right);
}

TEST(QuickSortTest, SomeTest) {
  int arr[8] = {1, 3, 2, 4, 999, 6};
  int sz = sizeof(arr)/sizeof(arr[0]);
  quicksort(arr, 0, sz - 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
