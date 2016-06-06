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

TEST(LaunchAsyncTest, SomeTest) {
  check_future();
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
