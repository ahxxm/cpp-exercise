#include <vector>
#include <string>

int main(int argc, char *argv[]) {
  // c++11 support this type of initialization
  std::vector<std::string> strong{"w",  "a",  "tu"};

  // typical style
  std::vector<std::string> biuf(10, "buff");

  // not when using old compilers, there should be a whitespace
  // between >>.
  std::vector<std::vector<int>> ivec;

  // no, ivec's a vector of vector..
  // std::vector<std::string> svec = ivec;

  // yes, 10 "null"
  std::vector<std::string> svec(10, "null");


  // how many elements are in these vector
  std::vector<int> v1;  // none
  std::vector<int> v2(10);  // 10
  std::vector<int> v3(10, 42);  // 10
  std::vector<int> v4{10};  // only 1: 10
  std::vector<int> v5{10, 42};  // 2: 10 and 42
  std::vector<std::string> v6{10};  // 10, 10 is not a string, thus it's actually (10)
  std::vector<std::string> v7 {10, "hi"};  // 10 * "hi"

  return 0;
}
