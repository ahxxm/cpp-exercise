#include <string>
#include <vector>
#include <iostream>


int main(void) {
  // this prints abcdeft, bcdefg, ..., g
  // because "compiler ordinarily converts the array to a pointer..",
  // the for-loop actually loops this iterator. Address-of operator
  // & restore it to [current location -- and -- later --char]..
  std::string chart = "abcdefg";
  for (char &c : chart) {
    std::cout << &c << std::endl;
  }

  // 31: 10 ints, position == value
  // compile time constant variable: k followed by CamelCase
  constexpr const int kLength = 10;
  int pv[kLength];
  for (int i = 0; i != kLength; i++) {
    pv[i] = i + 1;
    std::cout << pv[i] << std::endl;
  }

  // 32: 1) copy previous pv into another array
  // 2) rewrite this using vector
  int pv2[kLength];
  std::vector<int> pv3;
  for (int i = 0; i != kLength; i++) {
    pv2[i] = pv[i];
    pv3.push_back(pv[i]);
    std::cout << pv2[i] << std::endl;
    std::cout << pv3.back() << std::endl;
  }
}
