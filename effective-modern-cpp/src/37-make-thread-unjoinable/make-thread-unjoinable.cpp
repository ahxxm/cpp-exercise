#include <future>
#include <iostream>
#include <utility>
#include <vector>
#include "gtest/gtest.h"

// unjoinable:
// - default contructed: no function to execute
// - thread been moved from
// - already joined: after join, no longer correspond to underlying thread
// - detached

// joinable thread cause program terminate
// because:
// - implicit join: lead to performance issue that is hard to track
// - implicit detach: still changing variables

// FIXME: c++14
constexpr auto tenM = 10000000;
// constexpr auto teM = 10'000'000;


bool doWork(std::function<bool(int)> filter, int maxVal = tenM) {
  std::vector<int> goodVals;

  // FIXME: start threads suspended, item 39
  std::thread t ([&filter, maxVal, &goodVals] {
      for (auto i = 0; i <= maxVal; ++i) {
        if (filter(i)) {goodVals.push_back(i);}
      }
    });

  // opaque_pthread_t *
  auto nh = t.native_handle();
  std::cout << &nh << std::endl;

  // nh.aa();

  return true;
}


TEST(ThreadUnjoinableTest, SomeTest) {
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
