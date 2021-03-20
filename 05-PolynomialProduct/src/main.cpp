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
#include "Timer/timer.cpp"

int main(int argc, char const *argv[]) {
  // Build Two Polynomial
  Polynomial first_polynomial({5, 2});
  std::cout << first_polynomial << std::endl;
  Polynomial second_polynomial({1, 8});
  std::cout << second_polynomial << std::endl;

  timer([first_polynomial, second_polynomial]() {
    Product *product = new Product(new Classic());
    std::cout << product->ProductInterface(first_polynomial, second_polynomial);
  });
}
