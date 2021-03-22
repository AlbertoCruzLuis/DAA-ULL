#include "Monomial.hpp"

#include <cmath>

Monomial::Monomial() {
  coefficient_ = 0;
  exponent_ = 0;
}

Monomial::Monomial(int coefficient, int exponent)
    : coefficient_(coefficient), exponent_(exponent) {}

int Monomial::get_coefficient() const { return coefficient_; }

int Monomial::get_exponent() const { return exponent_; }

void Monomial::set_coefficient(int value) { coefficient_ = value; }

void Monomial::set_exponent(int value) { exponent_ = value; }

int Monomial::evaluate(int value_of_x) const {
  return coefficient_ * pow(value_of_x, exponent_);
}

std::istream& operator>>(std::istream& is, const Monomial& monomial) {}

std::ostream& operator<<(std::ostream& os, const Monomial& monomial) {
  if (monomial.get_coefficient() != 0) {
    if (monomial.get_coefficient() > 0) {
      os << "+";
    }
    os << monomial.get_coefficient();
    if (monomial.get_exponent() != 0) {
      os << "x";
    }
    if (monomial.get_exponent() > 1) {
      os << "^" << monomial.get_exponent();
    }
  }
  return os;
}

Monomial operator+(Monomial& monomial_x, Monomial& monomial_y) {
  if (monomial_x.exponent_ == monomial_y.exponent_) {
    int add_of_coefficients = monomial_x.coefficient_ + monomial_y.coefficient_;
    Monomial new_monomial(add_of_coefficients, monomial_x.exponent_);
    return new_monomial;
  }
}

Monomial operator-(Monomial& monomial_x, Monomial& monomial_y) {
  if (monomial_x.exponent_ == monomial_y.exponent_) {
    int sub_of_coefficients = monomial_x.coefficient_ - monomial_y.coefficient_;
    Monomial new_monomial(sub_of_coefficients, monomial_x.exponent_);
    return new_monomial;
  }
}

Monomial operator*(Monomial& monomial_x, Monomial& monomial_y) {
  int add_of_exponents = monomial_x.exponent_ + monomial_y.exponent_;
  int multiply_of_coefficients =
      monomial_x.coefficient_ * monomial_y.coefficient_;

  Monomial new_monomial(multiply_of_coefficients, add_of_exponents);
  return new_monomial;
}