#include "gtest/gtest.h"


typedef unsigned int Bit;
class File {
  // following the member name with a colon and
  // a constant expression specifying the number of bits:
  Bit mode: 2; //  mode has 2 bits
  Bit modified: 1;
public:
  enum modes {READ = 01, WRITE = 02, EXECUTE = 03};
  void close();
  void write();
  bool isRead();

  File &open(modes m) {
    mode |= READ; // set bit
    if (m & WRITE) {
      // do something
    };
    return *this;
  };
};


TEST(NonportableTest, SomeTest) {

}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
