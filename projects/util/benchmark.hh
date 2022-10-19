#pragma once

#include <chrono>
#include <cstdint>
#include <iostream>
#include <string>

class benchmark {
 private:
  std::chrono::time_point<std::chrono::steady_clock, std::chrono::nanoseconds>
      t0;
  double elapsedTime;
  std::string msg;

 public:
  benchmark(const std::string& msg) : msg(msg) { reset(); }

  void reset() { elapsedTime = 0; }

  void start() {
    t0 = time_point_cast<std::chrono::nanoseconds>(
        std::chrono::steady_clock::now());
  }

  void end() {
    std::chrono::time_point<std::chrono::steady_clock, std::chrono::nanoseconds>
			t1 = time_point_cast<std::chrono::nanoseconds>
			(std::chrono::steady_clock::now());
    elapsedTime += (t1 - t0).count();
  }

  constexpr double elapsed() const { return elapsedTime; }
  void display() const {
    cerr << msg << " elapsed time: " << elapsedTime << '\n';
  }
  void displayavg(uint64_t iterations) const {
    cerr << msg << " avg time: " << elapsedTime / iterations << '\n';
  }

  template <typename Func>
  constexpr static void benchmark(const std::string& msg,
                                  uint64_t numIterations, Func func) {
    uint64_t iter = numIterations;
    benchmark b(msg);
    b.start();
    for (; numIterations > 0; numIterations--) {
			func();
			cerr << numIterations << '\n';
    b.end();
    b.displayavg(iter);
  }
};
