#include <atomic>
#include <chrono>
#include <cstdlib>
#include <functional>
#include <future>
#include <iostream>
#include <mutex>
#include <thread>
#include <time.h>
#include <vector>

static void run_parallel(std::function<void(void)> func,
                         const unsigned int iterations = 1,
                         const unsigned int threadsNum = 8) {
  std::vector<std::thread> threads(threadsNum);

  for (auto &thread : threads) {
    thread = std::thread([&]() {
      for (unsigned int i = 0; i < iterations; ++i) {
        func();
      }
    });
  }

  std::cout << "thread_test have been created............. " << std::endl;

  for (auto &thread : threads) {
    if (thread.joinable()) {
      auto thread_id = thread.get_id();
      std::cout << "thread " << thread_id << " waiting" << std::endl;
      thread.join();
      std::cout << "thread " << thread_id << " has exited" << std::endl;
    }
  }
}

void thread_test() {

  std::mutex mutex;
  std::function<void(void)> func = [&]() {
    {
      std::lock_guard<std::mutex> lock(mutex);
      std::cout << "running thread " << std::this_thread::get_id() << std::endl;
    }
    srand((unsigned int)time(NULL));
    for (auto i = 0; i < 100; i++) {
      auto time = rand() % 100;
      std::this_thread::sleep_for(std::chrono::milliseconds(time));
      double value = 1.0;
      for (auto j = 1; j < 10000; j++)
        value = 3.1415926 * j * j - value / j;
    }
  };

  run_parallel(func);
  std::cout << "thread_test is done " << std::endl;
}

void async_test() {
  std::promise<int> p;
  std::future<int> f = p.get_future();

  std::thread t([&p] {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    p.set_value_at_thread_exit(12345);
  });
  t.detach();

  f.wait();
  std::cout << "Wait result: " << f.get() << std::endl;
}

int main(int argc, char **argv) {
  thread_test();
  async_test();
}
