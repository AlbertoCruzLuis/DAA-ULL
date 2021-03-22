#include "Polynomial.hpp"

Polynomial::Polynomial() : degree_(0) {}

Polynomial::Polynomial(std::vector<Monomial> monomials) {
  degree_ = monomials.size() - 1;
  terms_ = monomials;
}

/**
 * @brief Construct a new Polynomial:: Polynomial object
 *
 * @param coefs Array of Coeficients - Ej {3,0,4} = 3X^2 + 4
 */
Polynomial::Polynomial(std::vector<int> coefs) {
  degree_ = coefs.size() - 1;
  int current_exponent = coefs.size() - 1;
  for (auto&& coef : coefs) {
    terms_.push_back(Monomial(coef, current_exponent));
    current_exponent--;
  }
}

int Polynomial::get_degree() const { return degree_; }

std::vector<Monomial> Polynomial::get_terms() const { return terms_; }

int Polynomial::get_terms_size() const { return terms_.size(); }

void Polynomial::add_term(Monomial monomial) {
  degree_++;
  terms_.push_back(monomial);
}

Polynomial operator+(Polynomial& polynomial_x, Polynomial& polynomial_y) {
  // Add polynomials as if they were integers
  // and create polynomial of exponent 0
  // Ej 2x + 1 = 3

  Polynomial add;
  int add_coefficient = 0;
  for (size_t i = 0; i < polynomial_x.get_terms().size(); i++) {
    for (size_t j = 0; j < polynomial_y.get_terms().size(); j++) {
      if (polynomial_x.get_terms()[i].get_exponent() ==
          polynomial_y.get_terms()[j].get_exponent()) {
        add_coefficient += polynomial_x.get_terms()[i].get_coefficient() +
                           polynomial_y.get_terms()[j].get_coefficient();
        i++;
      } else if (polynomial_x.get_terms()[i].get_exponent() >
                 polynomial_y.get_terms()[i].get_exponent()) {
        add_coefficient += polynomial_x.get_terms()[i].get_coefficient();
        j--;
        i++;
      } else {
        add_coefficient += polynomial_y.get_terms()[i].get_coefficient();
      }
    }
  }
  add.add_term(Monomial(add_coefficient, 0));

  return add;
}

Polynomial operator-(Polynomial& polynomial_x, Polynomial& polynomial_y) {
  Polynomial sub;
  int sub_coefficient = 0;
  /*for (size_t i = 0; i < polynomial_x.get_terms().size(); i++) {
    for (size_t j = 0; j < polynomial_y.get_terms().size(); j++) {
      if (polynomial_x.get_terms()[i].get_exponent() ==
          polynomial_y.get_terms()[j].get_exponent()) {
        sub_coefficient += polynomial_x.get_terms()[i].get_coefficient() -
                           polynomial_y.get_terms()[j].get_coefficient();
        i++;
      } else if (polynomial_x.get_terms()[i].get_exponent() >
                 polynomial_y.get_terms()[i].get_exponent()) {
        sub_coefficient += polynomial_x.get_terms()[i].get_coefficient();
        j--;
        i++;
      } else {
        sub_coefficient += polynomial_y.get_terms()[i].get_coefficient();
      }
    }
  }*/
  for (size_t i = 0; i < polynomial_x.get_terms().size(); i++) {
    sub_coefficient += polynomial_x.get_terms()[i].get_coefficient() -
                       polynomial_y.get_terms()[i].get_coefficient();
  }

  sub.add_term(Monomial(sub_coefficient, 0));
  return sub;
}

Polynomial operator*(Polynomial& polynomial_x, Polynomial& polynomial_y) {}

std::ostream& operator<<(std::ostream& os, const Polynomial& polynomial) {
  for (auto&& monomial : polynomial.terms_) {
    os << monomial;
    if (monomial.get_coefficient() != 0) {
      os << " ";
    }
  }
  os << "\n";
}