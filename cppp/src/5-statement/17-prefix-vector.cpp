#include <iostream>
#include <vector>

bool is_prefix_of(std::vector<int> sub, std::vector<int> main) {
  //
  uint64_t subsize = sub.size();
  if (subsize > main.size()) {
    return false;
  }

  for (uint64_t index = 0; index != subsize; ++index) {
    if (sub[index] != main[index]) {
      return false;
    }
  }

  return true;
}

int main(void) {
// int main() {
  // null statement...............
  // ;

  while (1 == 2) {

  };

  int val = 0;

  // ; is necessary to separate statements..
  // a block is terminated by }
  // ...of course.
  while (val < 10) {
    ++val;
    ++val;
  };

  // switch
  // break in each case is recommended, or it will loop over ever case..

  int b = 2;
  int c = 0;
  switch (b) {
  case 2:
    c++;
    break;
  case 3:
    c += 2;
    break;
  }
  std::cout << c << std::endl;


  // 17: if vector is another vector's prefix
  std::vector<int> va = {0, 1, 1};
  std::vector<int> vc = {0, 1, 1, 2, 3, 4, 5};

  bool result = is_prefix_of(va, vc);
  std::cout << "Is prefix? " << result << std::endl;

}
