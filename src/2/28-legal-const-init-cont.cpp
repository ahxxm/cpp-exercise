#include <iostream>

int const_init_cont(){
  // int i, *const cp = 1.233;
  // FIXME: no, cp is not initialized. why it's treated as int??

  // const int ic,& r = ic;
  // no, ic is not initialized.

  // const int *const p3;
  // need initialize too.

  // p itself can change to point to other const objects.
  int i = 5;
  int j = 6;
  const int *p;
  p = &i;
  p = &j;

  return 0;
}
