#include <iostream>

void const_init_cont(){
  // int i, *const cp = 1.233;
  // no, cp is a const pointer to int, but 1.233 is not int.
  // to make this happen, define a int then point to it:
  // int jj = 233;int i,* const cp = &jj;

  // const int ic,& r = ic;
  // no, ic is not initialized.

  // const int *const p3;
  // need initialize too.

  // p itself can change to point to other const objects.
  int iv = 5;
  int j = 6;
  const int *p;
  p = &iv;
  p = &j;
}
