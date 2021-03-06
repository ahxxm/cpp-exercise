#include <iostream>


int main(void) {
  double d = 3.14;

  // couvert back to double pointer will preserve its values
  void *p = &d;
  std::cout << p << std::endl;

  double *dp = static_cast<double*>(p);
  std::cout << *dp << std::endl;

  // const_cast
  // ok, but writing *pcc is undefined.
  // "can be useful in context of overloaded functions, other uses often indicate design flaw."
  // also context of dynamic binding.. but template might be better.
  char u = 'u';
  const char *pc = &u;
  char *pcc = const_cast<char*>(pc);
  std::cout << *pcc << std::endl;

  // 36: make i*=j integral
  int i = 1;
  double j = 2.2;

  i *= static_cast<int>(j);
  std::cout << i << std::endl;
}
