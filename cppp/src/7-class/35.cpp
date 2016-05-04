#include <string>
#include "gtest/gtest.h"

// 35: explain following code, indicating which definition
// of Type or initVal is used for each use of those names.

// "Type" as alias of std::string
typedef std::string Type;

// new function initVal() that returns a Type
Type initVal() {
  return "";
}

class Exercise {
public:
  // overwrites Type with double
  // within class cope
  typedef double Type;

  // declare setVal that accepts double and returns
  // double
  Type setVal(Type);

  // Exercise::intVal() returns double
  // can't be default initialized.
  // fix: initialized as returning 0.0
  Type initVal() {
    return 0.0;
  };

  // self-defined
  Type getVal() {
    return val;
  }
private:
  int val;
};

// define setVal out of line
// it can't work because Type outside scope
// is string. fix: explicit type in definition.
// Type Exercise::setVal(Type parm) {
double Exercise::setVal(double parm) {
  val = parm + initVal();

  // return val;
  // can't return val, because return Type is string
  // and val is int.
  return val;  // fix
}

TEST(ScopeTest, SomeScopeTest) {
  Exercise e = Exercise();
  e.setVal(1.0);
  EXPECT_EQ(e.getVal(), 1.0);
  EXPECT_EQ(initVal(), "");
}


int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
