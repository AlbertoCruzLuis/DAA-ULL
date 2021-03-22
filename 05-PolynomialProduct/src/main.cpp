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

#include <iostream>

#include "Algorithm.hpp"
#include "Polynomial.hpp"
#include "Product.hpp"
#include "RandomPolynomials/random_polynomials.cpp"
#include "Timer/timer.cpp"

int main(int argc, char const *argv[]) {
  try {
    // Build Two Polynomial
    int case_size = 300;

    Polynomial first_polynomial(random_polynomials(case_size));
    std::cout << "1.Polinomio- " << first_polynomial << std::endl;
    Polynomial second_polynomial(random_polynomials(case_size));
    std::cout << "2.Polinomio- " << second_polynomial << std::endl;

    timer([first_polynomial, second_polynomial]() {
      Product *product = new Product(new Classic());
      product->ProductInterface(first_polynomial, second_polynomial);
    });

    timer([first_polynomial, second_polynomial]() {
      Product *product2 = new Product(new DivideConquer());
      product2->ProductInterface(first_polynomial, second_polynomial);
    });
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  } catch (const char *e) {
    std::cerr << e << '\n';
  } catch (...) {
  }
}
