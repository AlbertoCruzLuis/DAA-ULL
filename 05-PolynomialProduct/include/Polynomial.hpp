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

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <vector>

#include "Monomial.hpp"

/**
 * @brief Construct a Polynomial
 */
class Polynomial {
 private:
  int degree_;
  std::vector<Monomial> terms_;

 public:
  Polynomial();
  Polynomial(std::vector<int> coefficients);
  ~Polynomial() {}

  int get_degree();
  std::vector<Monomial> get_terms();
  void add_term(Monomial monomial);

  friend std::ostream& operator<<(std::ostream& os,
                                  const Polynomial& polynomial);
};

#endif  // POLYNOMIAL_H