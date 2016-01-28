#include <vector>

class Example {
public:
  // static double rate = 6.5;
  // non-const static must not be initialized
  // in class
  static double rate;

  static const int vecSize = 20;

  // static vector<double> vec(vecSize);
  // vecSize is not defined..
  static const std::vector<double> vec;
};
