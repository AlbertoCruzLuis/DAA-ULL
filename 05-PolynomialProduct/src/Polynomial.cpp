#include "Polynomial.hpp"

Polynomial::Polynomial() : degree_(0) {}

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

int Polynomial::get_degree() { return degree_; }

std::vector<Monomial> Polynomial::get_terms() { return terms_; }

void Polynomial::add_term(Monomial monomial) {
  degree_++;
  terms_.push_back(monomial);
}

std::ostream& operator<<(std::ostream& os, const Polynomial& polynomial) {
  for (auto&& monomial : polynomial.terms_) {
    os << monomial;
    if (monomial.get_coefficient() != 0) {
      os << " ";
    }
  }
  os << "\n";
}