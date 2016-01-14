#include <iostream>
#include <string>

int txt_size(){
  return 10;
}

int main(int argc, char *argv[]) {

  // 27 array initialization
  unsigned buf_size = 1024;
  int ia[buf_size];

  int ib[4 * 7 - 14];

  int ic[txt_size()];

  // place for null, st[12] will be ok
  // char st[11] = "fundamental";

  // 28 values in arrays
  // null string ""
  std::string sa[10];

  // 0
  int id[10];

  return 0;
}
