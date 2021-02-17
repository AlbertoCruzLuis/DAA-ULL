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

#ifndef __STRATEGY_H__
#define __STRATEGY_H__

#include "matrix.hpp"

class Strategy {
 public:
  virtual Matrix multiply(Matrix firstMatrix, Matrix secondMatrix) = 0;
};

class StrategyColumns : public Strategy {
 public:
  Matrix multiply(Matrix firstMatrix, Matrix secondMatrix) {
    if (firstMatrix.get_cols() == secondMatrix.get_rows()) {
      Matrix productMatrix(firstMatrix.get_rows(), secondMatrix.get_cols());
      int sumProducts = 0;
      for (size_t i = 0; i < firstMatrix.get_cols(); i++) {
        for (size_t j = 0; j < secondMatrix.get_rows(); j++) {
          for (size_t k = 0; k < firstMatrix.get_rows(); k++) {
            sumProducts += firstMatrix.get_value_pos(i, k) *
                           secondMatrix.get_value_pos(k, j);
          }
          productMatrix.set_value_pos(i, j, sumProducts);
          sumProducts = 0;
        }
      }
      return productMatrix;
    }
    throw "Error Incorrect Size of Matrix";
  }
};

class StrategyRows : public Strategy {
 public:
  Matrix multiply(Matrix firstMatrix, Matrix secondMatrix) {
    if (firstMatrix.get_cols() == secondMatrix.get_cols()) {
      Matrix productMatrix(firstMatrix.get_rows(), secondMatrix.get_cols());
      Matrix secondMatrixTransposed = secondMatrix.transposed();
      int sumProducts = 0;
      for (size_t i = 0; i < firstMatrix.get_cols(); i++) {
        for (size_t j = 0; j < secondMatrix.get_rows(); j++) {
          for (size_t k = 0; k < firstMatrix.get_rows(); k++) {
            sumProducts += firstMatrix.get_value_pos(i, k) *
                           secondMatrixTransposed.get_value_pos(j, k);
          }
          productMatrix.set_value_pos(i, j, sumProducts);
          sumProducts = 0;
        }
      }
      return productMatrix;
    }
    throw "Error Incorrect Size of Matrix";
  }
};

#endif  // __STRATEGY_H__