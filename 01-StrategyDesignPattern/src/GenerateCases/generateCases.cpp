/*=======================================================================
|| @Author: Alberto Cruz Luis
|| @Email: alu0101217734@ull.edu.es
|| @Github: https://github.com/AlbertoCruzLuis
|| @Date: February 2021
|| @University: ULL in Tenerife
|| @Version: 01-StrategyDesignPattern
|| @Info: https://sourcemaking.com/design_patterns/strategy
=======================================================================*/

#ifndef GENERATECASES_H
#define GENERATECASES_H

#include "../Timer/timer.cpp"
#include "matrix.hpp"
#include "strategyTest.cpp"

void generateCases(int sizeRowsOneMatrix, int sizeRowsTwoMatrix,
                   int sizeColsOneMatrix, int sizeColsTwoMatrix) {
  Matrix firstMatrix(sizeRowsOneMatrix, sizeColsOneMatrix, rand());
  Matrix secondMatrix(sizeRowsTwoMatrix, sizeColsTwoMatrix, rand());

  std::cout << "By Rows - ";
  timer([firstMatrix, secondMatrix]() {
    strategyRowsTest(firstMatrix, secondMatrix);
  });

  std::cout << "By Columns - ";
  timer([firstMatrix, secondMatrix]() {
    strategyColumnsTest(firstMatrix, secondMatrix);
  });

  std::cout << "\n";
}

#endif  // GENERATECASES_H