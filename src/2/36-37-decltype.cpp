#include <iostream>

// void decltype_wat() {
int main() {
  // two int
  int a = 3,  b = 4;

  // c is a copy of a
  decltype(a) c = a;

  // d is a reference to int
  // FIXME: but not to a? because ++d didn't change a
  decltype((b)) d = a;

  // increments c
  ++c;

  // increments d
  ++d;


  // e also has type of reference to int
  // but "a=b" didn't do anything, decltype uses type of a as evaluate result.
  // decltype(a = b) e = a;

}
