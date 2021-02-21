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

#include "GenerateCases/generateCases.cpp"

int main(int argc, char const *argv[]) {
  try {
    generateCases(100, 1000, 1000, 100);
    generateCases(500, 500, 500, 500);
    generateCases(500, 500, 500, 1000);
    generateCases(500, 1000, 1000, 100);
    generateCases(500, 100, 100, 1000);
  } catch (const std::exception &except) {
    std::cerr << except.what() << '\n';
  } catch (const char *except) {
    std::cerr << except;
  }

  return 0;
}
