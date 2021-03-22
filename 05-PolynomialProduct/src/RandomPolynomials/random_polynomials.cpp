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
#include <vector>

std::vector<int> random_polynomials(int case_size) {
  srand(time(NULL));
  std::vector<int> random_coefficients;
  for (size_t i = 0; i < case_size; i++) {
    random_coefficients.push_back(((rand() % 10) + 1));
  }
  return random_coefficients;
}