#include <chrono>
#include <future>
#include "gtest/gtest.h"

// std::async: request function be run according to std::async **launch policy**
// 2 policies:
// std::launch::async - must run asynchronously
// std::launch::deferred - may run when get() or wait() called on future object

// default policy is mixed, so no way to predict behavior.

int f() {
  return 42;
}


void check_future() {
  auto future = std::async(f);

  auto one_s = std::chrono::seconds(1);
  if (future.wait_for(one_s) == std::future_status::deferred) {
    // use get() or wait()
  } else {
    // wait for timeout
  }
}

// wrap assurance of asynchronous
// FIXME: C++14 replace return type with auto
template<typename F, typename... Ts>
inline std::future<typename std::result_of<F(Ts...)>::type >
reallyAsync(F &&f, Ts &&... params) {
  return std::async(std::launch::async,
                    std::forward<F>(f),
                    std::forward<Ts>(params)...);
}


TEST(LaunchAsyncTest, SomeTest) {
  check_future();

  auto future = reallyAsync(f);
  std::cout << future.get() << std::endl;

}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
