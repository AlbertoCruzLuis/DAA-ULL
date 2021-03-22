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
  Polynomial multiply(Polynomial &first, Polynomial &second) {
    Polynomial product;
    // Min Case
    if (first.get_terms().size() == 1 && second.get_terms().size() == 1) {
      Monomial multiply_of_monomials(first.get_terms()[0] *
                                     second.get_terms()[0]);
      product.add_term(multiply_of_monomials);
    } else {
      int size_term = first.get_terms()[0].get_exponent() * 2;
      std::pair<Polynomial, Polynomial> first_sub_problem = decompose(first);
      std::pair<Polynomial, Polynomial> second_sub_problem = decompose(second);
      Polynomial low =
          multiply(first_sub_problem.first, second_sub_problem.first);
      Polynomial high =
          multiply(first_sub_problem.second, second_sub_problem.second);
      Polynomial add_first = first_sub_problem.first + first_sub_problem.second;
      Polynomial add_second =
          second_sub_problem.first + second_sub_problem.second;
      Polynomial middle = multiply(add_first, add_second);

      Polynomial operation_one = middle - low;
      Polynomial middle_term = operation_one - high;
      Monomial middle_monomial(middle_term.get_terms()[0].get_coefficient(),
                               size_term - 1);
      Monomial low_monomial(low.get_terms()[0].get_coefficient(), size_term);

      product.add_term(low_monomial);
      product.add_term(middle_monomial);
      product.add_term(high.get_terms()[0]);
    }
    return product;
  }

  std::pair<Polynomial, Polynomial> decompose(Polynomial polynomial) {
    int middle = polynomial.get_terms_size() / 2;
    Polynomial low;
    Polynomial high;
    for (size_t i = 0; i < polynomial.get_terms_size(); i++) {
      if (i < middle) {
        low.add_term(polynomial.get_terms()[i]);
      } else {
        high.add_term(polynomial.get_terms()[i]);
      }
    }
    return std::make_pair(low, high);
  }
};

#endif  // ALGORITHM_H