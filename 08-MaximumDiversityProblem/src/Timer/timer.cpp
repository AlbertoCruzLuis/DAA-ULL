/*=======================================================================
|| @Author: Alberto Cruz Luis
|| @Email: alu0101217734@ull.edu.es
|| @Github: https://github.com/AlbertoCruzLuis
|| @Date: March 2021
|| @University: ULL in Tenerife
|| @Course: DAA
|| @Version: 05-PolynomialProduct
|| @Info: https://en.wikipedia.org/wiki/Polynomial_arithmetic
=======================================================================*/

#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <functional>
#include <iostream>

float timer(std::function<void()> func) {
  auto start = std::chrono::system_clock::now();
  func();
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<float, std::milli> duration = end - start;
  return duration.count();
}
#endif  // TIMER_H