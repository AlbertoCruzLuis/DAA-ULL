/*=======================================================================
|| @Author: Alberto Cruz Luis
|| @Email: alu0101217734@ull.edu.es
|| @Github: https://github.com/AlbertoCruzLuis
|| @Date: February 2021
|| @University: ULL in Tenerife
|| @Version: 01-StrategyDesignPattern
|| @Info: https://sourcemaking.com/design_patterns/strategy
=======================================================================*/

#include "matrix.hpp"

Matrix::Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  // Create Matrix rows * cols
  matrix_.resize(rows, std::vector<int>(cols, 0));
}

Matrix::Matrix(int rows, int cols, int randomSeed, int min_range, int max_range)
    : rows_(rows), cols_(cols) {
  matrix_.resize(rows, std::vector<int>(cols, 0));
  srand(randomSeed);
  fill_random_matrix(min_range, max_range);
}

int Matrix::get_rows() const { return rows_; }

int Matrix::get_cols() const { return cols_; }

int Matrix::get_value_pos(int row, int col) const { return matrix_[row][col]; }

void Matrix::set_value_pos(int row, int col, int value) {
  matrix_[row][col] = value;
}

Matrix Matrix::transposed() {
  Matrix matrixTransposed(rows_, cols_);
  for (size_t i = 0; i < rows_; i++) {
    for (size_t j = 0; j < cols_; j++) {
      matrixTransposed.set_value_pos(i, j, matrix_[j][i]);
    }
  }
  return matrixTransposed;
}

void Matrix::fill_random_matrix(int min_range, int max_range) {
  for (size_t i = 0; i < rows_; i++) {
    for (size_t j = 0; j < cols_; j++) {
      int range = max_range - min_range;
      matrix_[i][j] = (rand() % range) + min_range;
    }
  }
}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
  for (auto&& rows : matrix.matrix_) {
    for (auto&& cell : rows) {
      os << cell << " ";
    }
    os << "\n";
  }
  return os;
}