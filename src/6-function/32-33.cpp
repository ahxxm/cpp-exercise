#include <iostream>
#include <vector>

// 32: explain these program
// get() returns a int &, main changes value in ia
// to its index.
int &get(int *arry, int index) {
  return arry[index];
}

int get_main(int argc, char *argv[]) {
  int ia[10];
  for (int i = 0;i != 10; ++i) {
    get(ia, i) = i;
  }

  // for (int j: ia) {
  // std::cout << j << std::endl;
  // }

  return EXIT_SUCCESS;
}


// 33: recursively print vector content
void loop_pointer_and_print(std::vector<int>::iterator &vec_ptr) {
  // FIXME: what if it's zero..
  if (*vec_ptr) {
    std::cout << *vec_ptr << std::endl;
    ++vec_ptr;
    loop_pointer_and_print(vec_ptr);
  } else {
    return;
  }
}

void recursively_print_vector(std::vector<int> &vec) {
  decltype(std::begin(vec)) begin = vec.begin();
  loop_pointer_and_print(begin);
}

int main(int argc, char *argv[]) {
  std::vector<int> va;
  for (int i = 1; i != 10; ++i) {
    va.push_back(i);
  }

  recursively_print_vector(va);

  return 0;
}
