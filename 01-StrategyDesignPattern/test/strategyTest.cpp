/*=======================================================================
|| @Author: Alberto Cruz Luis
|| @Email: alu0101217734@ull.edu.es
|| @Github: https://github.com/AlbertoCruzLuis
|| @Date: February 2021
|| @University: ULL in Tenerife
|| @Version: 01-StrategyDesignPattern
|| @Info: https://sourcemaking.com/design_patterns/strategy
=======================================================================*/

#ifndef STRATEGYTEST_H
#define STRATEGYTEST_H

#include <iostream>

#include "context.hpp"
#include "matrix.hpp"
#include "strategy.hpp"

void strategyColumnsTest(Matrix firstMatrix, Matrix secondMatrix) {
  Context *context;

  context = new Context(new StrategyColumns());
  context->ContextInterface(firstMatrix, secondMatrix);
}

void strategyRowsTest(Matrix firstMatrix, Matrix secondMatrix) {
  Context *context;

  context = new Context(new StrategyRows());
  context->ContextInterface(firstMatrix, secondMatrix);
}
#endif  // STRATEGYTEST_H