#include <future>
#include <thread>
#include "gtest/gtest.h"


int doAsyncWork() {return 42;}

void run() {
  // thread-based approach
  std::thread t(doAsyncWork);

  // task-based, avoid:
  // thread exhaustion
  // oversubscription
  // load balancing
  auto future = std::async(doAsyncWork);

}

TEST(PreferTaskTest, SomeTest) {
  run();
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
