#include <iostream>

int main(int argc, char *argv[]) {
  // Definitions given by the book
  int i = 0;
  const int v2 = 1;
  int v1 = v2;
  int *p1 = &v1, &r1 = v1;
  const int *p2 = &v2, *const p3 = &i, &r2 = v2;
  std::cout << r2 << std::endl;

  // legal tests

  // yes, r1 is a reference.
  r1 = v2;

  // p1 = p2;
  // no, p1 does not point to const int.

  // yes, previously p2 points to v2, now it points to v1.
  p2 = p1;

  // p1 = p3;
  // no, p3 is "const int *const".

  // yes, it points to converted const value, then converted i(what p3 points to).
  p2 = p3;
}
