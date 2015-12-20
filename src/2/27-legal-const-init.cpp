#include <iostream>

int const_init(){
  // of course fine
  int i1 = -1;

  // non-const reference can't bind tmp value
  // int &r = 0;

  // read from right to left,
  // const p2 is a const pointer of type int, points to i1
  // p2 itself can't be changed, but it can change i1
  int *const p2 = &i1;
  *p2 = 666;

  // r is not decleared, here & serves as an de-reference
  // operator
  // & r = 0;

  // only differen with p2 is that, p4 is read-only
  const int *const p4 = &i1;

  // points to a converted tmporary const int object
  const int *p5 = &i1;

  //
  const int i2 = i1;
  std::cout <<& i2 << std::endl;

}
