#include <iostream>
#include <string>
#include <vector>

bool is_odd(const int &j) {

  // (int) is deprecated
  if (static_cast<int>((j - 1) / 2) == static_cast<int>(j / 2)) {
    return true;
  }

  return false;
}

int main(void) {

  // member access operator ->
  std::string s1 = "string";
  std::string *pp = &s1;
  auto nn = pp->size();
  std::cout << nn << std::endl;

  // 21: double odd value in vector
  // using ?: operator...
  std::cout << "Double odd value" << std::endl;
  std::vector<int> va {1, 2, 3, 4, 5, 6, 7};
  for ( int &i: va ) {
    if (is_odd(i)) {
      // i *= 2;
      std::cout << "Doubled: " << i * 2 << std::endl;
    };

    // ?: usage
    std::cout << i << " " << ((int((i - 1) /  2) !=  int(i / 2)) ? "is even" : "is odd") << std::endl;

  }

  // 23: fix error caused by operator precedence
  std::string s = "word";
  std::string pl = s + (s[s.size() - 1] == 's' ? "" : "s");
  std::cout << pl << std::endl;
}
