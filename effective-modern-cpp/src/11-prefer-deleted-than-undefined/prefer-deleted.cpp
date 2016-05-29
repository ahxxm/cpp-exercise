#include "gtest/gtest.h"


bool isLucky(int) {return false;}

// rejects double and floats
// because C++ prefers convert float to double than int
bool isLucky(double) = delete;


// delete can also be used to prevent template instantiations
// char* and void* are often not wanted
template<typename T>
void processPtr(T *) {}

template<>
void processPtr<void>(void *) = delete;

template<>
void processPtr<char>(char *) = delete;


TEST(DeletedTest, SomeTest) {

}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
