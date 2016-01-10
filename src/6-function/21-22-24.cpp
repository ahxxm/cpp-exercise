#include <iostream>

// 21: take int and pointer, return larger one
int return_larger_int(const int &i, const int *j) {
  if (i < *j) {
    return *j;
  } else {
    return i;
  }
}

// 22: swap 2 integers
void swap_two_int(int &i, int &j) {
  int tmp = i;
  i = j;
  j = tmp;
}

// 23: explain and/or fix
// prints an int[10]
void print(const int ia[10]) {
  for (size_t i = 0; i != 10; ++i) {
    std::cout << ia[i] << std::endl;

  }
}

// int main(int argc, char *argv[]) {
void exercise_21_to_23(void) {
  int i = 10;
  int j = 42;
  int *k = &j;

  int result = return_larger_int(i, k);
  std::cout << result << std::endl;

  std::cout << "Now swap i 10 and j 42." << std::endl;
  swap_two_int(i, j);
  std::cout << "New i: " << i << std::endl;

  int ia[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  print(ia);
}
