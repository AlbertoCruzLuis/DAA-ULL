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

#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <algorithm>

#include "Polynomial.hpp"

class Algorithm {
 public:
  virtual Polynomial multiply(Polynomial &first, Polynomial &second) = 0;
};

class Classic : public Algorithm {
 public:
  Polynomial multiply(Polynomial &first, Polynomial &second) {
    Polynomial product;
    int max_terms =
        std::max(first.get_terms().size(), second.get_terms().size());
    int add;
    int terms_of_product = (2 * max_terms) - 2;
    for (size_t i = 0; i <= terms_of_product; i++) {
      add = 0;
      for (size_t j = 0; j <= i; j++) {
        if ((i - j) < first.get_terms().size() &&
            j < second.get_terms().size()) {
          add += first.get_terms()[j].get_coefficient() *
                 second.get_terms()[i - j].get_coefficient();
        }
      }
      product.add_term(Monomial(add, terms_of_product - i));
    }
    return product;
  }
};

class DivideConquer : public Algorithm {
 public:
  Polynomial multiply(Polynomial &first, Polynomial &second) {}
};

#endif  // ALGORITHM_H