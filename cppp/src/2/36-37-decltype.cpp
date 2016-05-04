#include <assert.h>
#include <iostream>
#include <typeinfo>  // required by typeid


int main(void) {
  // two int
  int a = 3, b = 4;

  // c is a copy of a
  decltype(a) c = a;
  assert(&c != &a);

  decltype(b) d = a;
  assert(typeid(d).hash_code() == typeid(a).hash_code());

  // increments d
  ++d;
  assert(d != a);


  // e also has type of reference to int
  // but "a=b" didn't do anything, decltype uses type of a as evaluate result.
  // decltype(a = b) e = a;

}
