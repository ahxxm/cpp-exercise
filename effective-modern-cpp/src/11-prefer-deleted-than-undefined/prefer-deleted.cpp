#include "gtest/gtest.h"


bool isLucky(int) {return false;}

// rejects double and floats
// because C++ prefers convert float to double than int
bool isLucky(double) = delete;


// delete instantiation can still be invoked:
// http://coliru.stacked-crooked.com/a/fdd716badcd72bf1
// http://stackoverflow.com/questions/21028144/when-is-deleting-a-template-instantiation-preferable-to-deleting-a-non-template

// delete can also be used to prevent template instantiations
// ONLY/MUST be written at namespace scope, not class scope.
// char* and void* are often not wanted
// also const char*, const volatile char*...
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
