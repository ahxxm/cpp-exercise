// top level const equals to redeclare
int lookup(char);
int lookup(const char);

// const to reference or pointer are low level
// this way lookup is overloaded: compiler can
// use constness of argument to distinguish
int lookup(char&);
int lookup(const char&);

int lookup(char *);
int lookup(const char *);

// 39: explain each second declaration
// a): overload
int calc(int, int);
int calc(const int, const int);

// b): error, functions that differ only by return type
// can't be overloaded
int get();
// double get();

// c): overload..
int *reset(int *);
double *reset(double *);


int main(void) {

  return 0;
}
