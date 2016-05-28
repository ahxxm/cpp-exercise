#include <memory>
#include <mutex>
#include "gtest/gtest.h"


void f(int) {}
void f(bool) {}
void f(void *) {}


void ff() {
  f(0);

  // ambiguous, typically calls f(int)
  // if NULL is 0L, conversion o int bool void*
  // is considered equally good
  // f(NULL);

  // nullptr does not have integral type
  // no pointer type either, but "think of it as a pointer of all types"
  // std::nullptr_t FIXME: "wonderful circular definition"
  f(nullptr);
}

int f1(std::shared_ptr<int>) {return 42;}

using MuxGuard = std::lock_guard<std::mutex>;
template<typename FuncType, typename MuxType, typename PtrType>
auto lockAndCall(FuncType func, MuxType &mutex, PtrType ptr)->decltype(func(ptr)) {
  MuxGuard g(mutex);
  return func(ptr);
}

void mu() {
  std::mutex f1m;

  // 0 or NULL won't work because shared_ptr requires pointer
  // template deducts "wrong" type for them.
  auto result1 = lockAndCall(f1, f1m, nullptr);
  std::cout << &result1 << std::endl;

}

TEST(NullptrTest, SomeTest) {
  ff();
  mu();
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
