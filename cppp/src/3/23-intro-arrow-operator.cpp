#include <vector>
#include <iostream>


int main(void) {

  // create a vector of length 10
  // any elegant solution? seems no, this is efficient, though lengthy...
  std::vector<int> ten;
  for (int i = 0; i != 10; i++) {
    ten.push_back(i);
  };

  // double each element, print this vector
  for (auto j = ten.begin(); j != ten.end(); ++j) {
    *j *= 2;
    std::cout <<* j << std::endl;
  }
}
