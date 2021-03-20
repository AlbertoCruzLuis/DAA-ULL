#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <functional>
#include <iostream>

void timer(std::function<void()> func) {
  auto start = std::chrono::system_clock::now();
  func();
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<float, std::milli> duration = end - start;
  std::cout << duration.count() << " ms\n";
}
#endif  // TIMER_H