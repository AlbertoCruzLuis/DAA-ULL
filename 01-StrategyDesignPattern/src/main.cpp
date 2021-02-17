/*=======================================================================
|| @Author: Alberto Cruz Luis
|| @Email: alu0101217734@ull.edu.es
|| @Github: https://github.com/AlbertoCruzLuis
|| @Date: February 2021
|| @University: ULL in Tenerife
|| @Version: 01-StrategyDesignPattern
|| @Info: https://sourcemaking.com/design_patterns/strategy
=======================================================================*/

#include <chrono>
#include <iostream>

#include "Timer/timer.cpp"
#include "matrix.hpp"
#include "strategyTest.cpp"

int main(int argc, char const *argv[]) {
  try {
    Matrix firstMatrix(500, 500, rand());
    Matrix secondMatrix(500, 500, rand());

    std::cout << "By Columns\n";
    timer([firstMatrix, secondMatrix]() {
      strategyColumnsTest(firstMatrix, secondMatrix);
    });

    std::cout << "By Rows\n";
    timer([firstMatrix, secondMatrix]() {
      strategyRowsTest(firstMatrix, secondMatrix);
    });

  } catch (const std::exception &except) {
    std::cerr << except.what() << '\n';
  } catch (const std::string &except) {
    std::cerr << except;
  }

  return 0;
}
