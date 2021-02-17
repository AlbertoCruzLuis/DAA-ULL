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

#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <iostream>
#include <vector>

class Matrix {
 private:
  int rows_;
  int cols_;
  std::vector<std::vector<int>> matrix_;

 public:
  Matrix() {}
  Matrix(int rows, int cols);
  Matrix(int rows, int cols, int randomSeed, int min_range = 0,
         int max_range = 10);
  ~Matrix() {}
  int get_rows() const;
  int get_cols() const;
  Matrix transposed();
  void fill_random_matrix(int min_range = 0, int max_range = 10);
  int get_value_pos(int row, int col) const;
  void set_value_pos(int row, int col, int value);

  friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
};

#endif  // __MATRIX_H__