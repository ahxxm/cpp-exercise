#include <iostream>

void swap_value(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}


// int main(int argc, char *argv[]) {
void swap_value_exercise() {
  int i = 2, j = 5;
  swap_value(&i, &j);

  std::cout << i << std::endl;
  std::cout << j << std::endl;

}
