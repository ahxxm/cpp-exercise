#include <cstring>
#include <iostream>

int main(int argc, char *argv[]) {

  // new for format to assign value to array
  const std::size_t row = 3, col = 4;
  int ia[row][col];

  // 43: print array of array
  // without `auto`
  for (int (&row)[col]: ia) {
    for (int &col: row) {
      // `col` without `&`, array element's value won't change
      // because that way a new col is created by copy previous value..
      col = 5;
      // dangerous: col++;
      std::cout << col << std::endl;
    }
  }

  // pointer type is type of first element
  int (*p)[col] = ia;
  // int *ip[col]; // this is an array of pointers to int
  std::cout << (*p)[2]<< std::endl;

  // 43:
  std::cout << "loop to print all value" << std::endl;
  for (int (*p)[col] = std::begin(ia); p != std::end(ia); ++p) {
    for (int *q = std::begin(*p); q != std::end(*p); q++) {
      std::cout << *q<< std::endl;
    }
    std::cout << std::endl;
  }

}
