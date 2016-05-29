#include <iostream>


// Reference param is preferred because it does not copy object and initialize.
void swap_value(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}


int main(void) {
  int i = 2, j = 5;
  swap_value(&i, &j);

  std::cout << i << std::endl;
  std::cout << j << std::endl;

}
