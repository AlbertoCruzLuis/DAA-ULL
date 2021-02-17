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