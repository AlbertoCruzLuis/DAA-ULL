/*=======================================================================
|| @Author: Alberto Cruz Luis
|| @Email: alu0101217734@ull.edu.es
|| @Github: https://github.com/AlbertoCruzLuis
|| @Date: February 2021
|| @University: ULL in Tenerife
|| @Course: DAA
|| @Version: 01-StrategyDesignPattern
|| @Info: https://sourcemaking.com/design_patterns/strategy
=======================================================================*/

#ifndef __CONTEXT_H__
#define __CONTEXT_H__

#include "matrix.hpp"
#include "strategy.hpp"

class Context {
 private:
  Strategy *_strategy;

 public:
  // Constructor
  Context(Strategy *strategy) { _strategy = strategy; }

  Matrix ContextInterface(Matrix firstMatrix, Matrix secondMatrix) {
    return _strategy->multiply(firstMatrix, secondMatrix);
  }
};

#endif  // __CONTEXT_H__