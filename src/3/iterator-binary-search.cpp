#include <string>
#include <iostream>
#include <vector>

int binary(std::vector<int> wut, int target){
  // binary search using iterator..
  auto left = wut.begin();
  auto right = wut.end();
  if (target < *left || target > * (right - 1)) {
    return - 1;
  }

  auto mid = left + (right - left) / 2;
  while ( *mid != target && mid != left) {
    if ( *mid > target) {
      right = mid;
    } else  {
        left = mid;
      }

    // unconciously avoided big vector overflow bug...
    mid = left + (right - left) / 2;
  }

  return (mid - wut.begin());
}


int main(int argc, char *argv[]){

  std::vector<int> wut;
  for (int i = 50; i != 10000; i++) {
    wut.push_back(i);
  }

  int target = 9999;
  int index = binary(wut, target);
  std::cout << "index of " << target << " in the list is:" << index << std::endl;

  return 0;
}
