#include <future>
#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
#include "gtest/gtest.h"

// copied from cppreference

std::mutex m;
std::condition_variable cv;
std::string data;
bool ready = false;
bool processed = false;

void worker_thread() {
  // Wait until main() sends data
  std::unique_lock<std::mutex> lk(m);
  cv.wait(lk, []{return ready;});

  // after the wait, we own the lock.
  std::cout << "Worker thread is processing data\n";
  data += " after processing";

  // Send data back to main()
  processed = true;
  std::cout << "Worker thread signals data processing completed\n";

  // Manual unlocking is done before notifying, to avoid waking up
  // the waiting thread only to block again (see notify_one for details)
  lk.unlock();
  cv.notify_one();
}

void c() {
  std::thread worker(worker_thread);

  data = "Example data";
  // send data to the worker thread
  {
    std::lock_guard<std::mutex> lk(m);
    ready = true;
    std::cout << "main() signals data ready for processing\n";
  }
  cv.notify_one();

  // wait for the worker
  {
    std::unique_lock<std::mutex> lk(m);
    cv.wait(lk, []{return processed;});
  }
  std::cout << "Back in main(), data = " << data << '\n';

  worker.join();
}



// Requires superfluous mutex, contriants on relative progress
// of detect/react, verify condvar.
// Flag avoid this by heavy resource usage: polling.
// std::promise dodges this, but use heap for shared states,
// can be only used for one-shot.
std::promise<void> p;

void detect() {

  auto sf = p.get_future().share();
  std::vector<std::thread> vt;

  for (int i = 0; i < 42; ++i) {
    // wait on
    // local copy of shared future
    vt.emplace_back([sf] {
        sf.wait();
        // react()
      });
  }


  // unsuspend all threads
  p.set_value();

  for (auto &t : vt) {
    t.join();
  }

}


TEST(VoidFutureTest, SomeTest) {
  c();
  detect();
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
