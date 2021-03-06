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

// constexpr auto tenM = 10000000;
constexpr auto tenM = 10'000'000;


bool fil(int i) {
  return i % 2 == 0;
}

bool doWork(std::function<bool(int)> filter, int maxVal = tenM) {
  std::vector<int> goodVals;

  std::thread t([&filter, maxVal, &goodVals] {
      for (auto i = 0; i <= maxVal; ++i) {
        if (filter(i)) {goodVals.push_back(i);}
      }
    });

  // opaque_pthread_t *
  // "enable realtime scheduling of C++ threads on a POSIX system"
  auto nh = t.native_handle();
  std::cout << &nh << std::endl;

  if (t.joinable()) {
      t.join();
  }
  return true;
}

// RAII: resource acquisition is initialization
enum class DtorAction {join, detach};
class ThreadRAII {
public:
  ThreadRAII(std::thread &&t, DtorAction a): action(a), t(std::move(t)) {};

  ~ThreadRAII() {
    // no race condition between joinable() and join()
    // because it's in destructor, no other thread should be make member function calls to t
    if (t.joinable()) {
      if (action == DtorAction::join) {
        t.join();
      } else {
        t.detach();
      }
    }

  }

  std::thread &get() {return t;};

private:
  DtorAction action;
  std::thread t;
};


TEST(ThreadUnjoinableTest, SomeTest) {
  ThreadRAII(std::thread(), DtorAction::join);
  doWork(fil, 100);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
