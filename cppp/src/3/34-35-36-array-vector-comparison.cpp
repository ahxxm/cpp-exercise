#include <assert.h>
#include <array>
#include <iostream>
#include <vector>


bool array_compare(int *a, int *b) {
  if ( *a != *b) {
    return false;
  }
  return true;
}

bool vector_compare(std::vector<int> a, std::vector<int> &b) {
  if (a.size() != b.size()) {
    return false;
  }

  for (int i = 0; i!= a.size(); i++) {
    if (a[i] != b[i]) {
      return false;
    }
  }

  return true;
}

int main(int argc, char *argv[]) {

  // 34: even p1 points to a[10], it still works
  int a[] = {1, 2, 3, 4, 5};
  int *p1 = a;
  int *p2 = &a[2];
  std::cout << (p2 - p1) << std::endl;
  p1 += p2 - p1;
  std::cout << *p1 << std::endl;

  // 35: use pointer to set array elements to 0
  int b[] = {1, 2, 3, 4, 5};
  auto end = std::end(b);
  for (int *b1 = b; b1 != end; b1++) {
    *b1 = 0;
  }

  // array defined in this way are "decaying"
  // into pointers.. to compare, use std::array or vector
  // More: http://stackoverflow.com/questions/12866413/comparing-arrays-c
  int c[] = {1, 2, 3, 4, 5};
  auto d = c; // d is a pointer
  assert(*d == 1);
  bool result = array_compare(c, b);
  std::cout << "Array comparison result: " << std::endl;
  std::cout << result << std::endl;

  // vector comparison
  std::vector<int> va {1, 2, 3, 4, 5};
  std::vector<int> vb {1, 2, 3, 4, 5};
  bool result_vector = vector_compare(va, vb);
  std::cout << "Vector comparison result: "<< std::endl;
  std::cout << result_vector << std::endl;


  return 0;
}
