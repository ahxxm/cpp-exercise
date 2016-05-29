#include <vector>
#include <string>
#include <iostream>


int main(void) {

  // 18: index/subscription does not change a vector, use push_back
  // instead
  std::vector<std::string> miu;
  miu.push_back("something");

  // 19: initialize with 10 * "42"
  std::vector<std::string> v1(10, "42");
  std::vector<std::string> v2;  // manually..
  for (int i = 0; i < 10; i++) {
    v2.push_back("42");
  }

  // 20: vector<int> print
  // wat{1,2,3,4} or wat={1,2,3,4} does not work for OSX's default clang++
  std::vector<int> wat {1, 2, 3, 4};
  // wat.push_back(1);
  // wat.push_back(2);
  // wat.push_back(4);

  // sum of adjacent ones: loop till last one
  int j = wat.size() - 1;
  for (int i = 0; i < j; i++) {
    std::cout << wat[i] + wat[i + 1] << std::endl;
  }

  // first and last element
  std::cout << wat[0] << "wat" << wat[j] << std::endl;

  // count the size, iterator minus yields long type object
  auto length = wat.end() - wat.begin();
  std::cout << length << std::endl;

  // or just use iterator: .end() points to off-the-end, * to dereference out a reference
  // to actual element
  std::cout << *wat.begin() << "wat" << * --wat.end() << std::endl;
}
