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

#ifndef PRODUCT_H
#define PRODUCT_H

#include "Algorithm.hpp"
#include "Polynomial.hpp"

class Product {
 private:
  Algorithm* algorithm_;

 public:
  Product(Algorithm* algorithm) { algorithm_ = algorithm; }
  ~Product() {}

  Polynomial ProductInterface(Polynomial first, Polynomial second) {
    return algorithm_->multiply(first, second);
  }
};
#endif  // PRODUCT_H