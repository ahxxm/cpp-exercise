#include "gtest/gtest.h"


// union is special kind of class:
// - might have multiple data members,
// but only one of them may have a value.
// - storage needed is its largest data member.
// - once a value is assigned, others become undefined.
// - can't have a reference member.
// - may not inherit or be inherited from,
// no virtual function.

union Token {
  char cval;
  int ival;
  double dval;
};

void union_test() {
  Token first_token = {'a'};
  Token last_token;
  last_token.ival = 2;
  Token *pt = new Token;

  std::cout << first_token.cval << std::endl;
  std::cout << last_token.ival << std::endl;
  pt->dval = 42.0;

};


TEST(UnionTest, SomeTest) {
  union_test();
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
