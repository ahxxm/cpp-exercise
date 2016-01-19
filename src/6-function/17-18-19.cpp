#include <iostream>
#include <string>
#include <vector>

// exercise 17
bool capital_letter_in_string(const std::string &s) {

  // for (const char cha: s) { // c++11
  for (decltype(s.begin()) cha = s.begin(); cha != s.end(); ++cha) {
    if (isupper(*cha)) {
      return true;
    }
  }

  return false;
}

// exercise 17
std::string string_to_lowercase(std::string s) {
  for (decltype(s.begin()) cha = s.begin(); cha != s.end(); ++cha) {
    *cha = tolower(*cha);
  }
  return s;
}

// exercise 18
// (a)
class matrix {};
// bool compare_matrix(matrix &a, matrix & b) {
// FIXME: to diminish warning..
// if (&a == &b) {
// return true;
// }
// return false;
// }

// (b)
std::vector<int> compare_value_in_vector(const int &num, const std::vector<int> &vec) {
  std::vector<int> result;


  if (vec.size() == 0) {
    return result;
  }

  for (decltype(vec.begin()) i = vec.begin(); i != vec.end(); ++i) {
    if ( *i == num) {
      result.push_back(1);
    } else {
      result.push_back(0);
    };
  };

  return result;
}

// exercise 19: legal or illegal call
// given declarations
void exercise_19(void) {
  double calc(double);
  int count(const std::string &, char);
  int sum(std::vector<int>::iterator, std::vector<int>::iterator, int);
  std::vector<int> vec(10);

  // calc(23.4, 55.1); // no calc with 2 double as param
  // int a_count = count("abcda", 'a');
  // double calc_66 = calc(66);
  // int sum_vec = sum(vec.begin(), vec.end(), 3.8); // 3.8 is a double
}

int main(int argc, char *argv[]) {
  exercise_19();
  bool result = capital_letter_in_string("tesT");
  bool result_2 = capital_letter_in_string("test");
  std::cout << result << std::endl;
  std::cout << result_2 << std::endl;


  std::string test = "teSt";
  std::string lower_test = string_to_lowercase(test);
  std::cout << test << " to lower: " << lower_test << std::endl;
  std::cout << "Origin string is unchanged: " << test << std::endl;

  int i = 2;
  // std::vector<int> j = {1, 2, 3, 4, 5}; // this is c++11 init syntax
  // old C++ can initialize vector using 2 pointer
  int j[] = {1, 2, 3, 4, 5};
  std::vector<int> k(j, j + sizeof(j) / sizeof(j[0]));
  std::vector<int> comparison = compare_value_in_vector(i, k);

  std::vector<int> empty_k;
  std::vector<int> comparison_2 = compare_value_in_vector(i, empty_k);

  // print comparison result
  for (decltype(comparison.begin()) j = comparison.begin(); j != comparison.end(); ++j) {
    std::cout << *j << std::endl;
  }

}
