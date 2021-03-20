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

#ifndef MONOMIAL_H
#define MONOMIAL_H

#include <iostream>

class Monomial {
 private:
  int coefficient_;
  int exponent_;

 public:
  Monomial() {}
  Monomial(int coefficient, int exponent);
  ~Monomial() {}

  int get_coefficient() const;
  int get_exponent() const;
  void set_coefficient(int value);
  void set_exponent(int value);
  int evaluate(int value_of_x) const;

  friend Monomial operator+(const Monomial& monomial_x,
                            const Monomial& monomial_y);

  friend Monomial operator-(const Monomial& monomial_x,
                            const Monomial& monomial_y);

  friend Monomial operator*(const Monomial& monomial_x,
                            const Monomial& monomial_y);

  friend std::ostream& operator<<(std::ostream& os, const Monomial& monomial);
  friend std::istream& operator>>(std::istream& is, const Monomial& monomial);
};

#endif  // MONOMIAL_H