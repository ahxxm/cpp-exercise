#include <vector>
#include "gtest/gtest.h"

// TODO: modify to count inversion

using TT = std::vector<int>;

TT merge(const TT &a, const TT &b) {
  // merge sorted vector
  TT result = {};

  // loop over 2 vector
  unsigned long i = 0, j = 0;
  while (i < a.size() && j < b.size()) {
    if (a.at(i) <= b.at(j)) {
      result.emplace_back(a.at(i));
      i++;
    } else {
      result.emplace_back(b.at(j));
      j++;
    }
  }

  while (i < a.size()) {
    result.emplace_back(a.at(i));
    i++;
  }

  while (j < b.size()) {
    result.emplace_back(b.at(j));
    j++;
  }

  return result;
}

void print(const TT &vec) {
  for (auto i : vec) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}


TT merge_sort(TT &vec) {
  if (vec.size() < 2) {
    return vec;
  };

  std::cout << "Receive vec:" << std::endl;
  print(vec);
  std::cout << std::endl;


  TT left(vec.begin(), vec.begin() + vec.size() / 2);

  std::cout << "Receive left:" << std::endl;
  print(left);
  std::cout << std::endl;

  left = merge_sort(left);

  std::cout << "Done left:" << std::endl;
  print(left);
  std::cout << std::endl;


  TT right(vec.begin() + vec.size() / 2, vec.end());

  std::cout << "Receive right:" << std::endl;
  print(right);
  std::cout << std::endl;


  right = merge_sort(right);

  std::cout << "Done right:" << std::endl;
  print(right);
  std::cout << std::endl;

  auto result = merge(left, right);

  std::cout << "Merged:" << std::endl;
  print(result);
  std::cout << std::endl;

  return result;
}


TEST(MergeSortTest, SomeTest) {
  TT a {1, 4, 5};
  TT b {2, 3};
  TT result = {1, 2, 3, 4, 5};
  auto c = merge(a, b);
  EXPECT_EQ(c, result);

  TT d = {1, 5, 4, 2, 3};
  EXPECT_EQ(merge_sort(d), result);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
