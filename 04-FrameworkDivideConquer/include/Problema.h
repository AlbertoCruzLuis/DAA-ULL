/*=======================================================================
|| @Author: Alberto Cruz Luis
|| @Email: alu0101217734@ull.edu.es
|| @Github: https://github.com/AlbertoCruzLuis
|| @Date: March 2021
|| @University: ULL in Tenerife
|| @Course: DAA
|| @Version: 04-FrameworkDivideConquer
|| @Info: https://es.wikipedia.org/wiki/Algoritmo_divide_y_vencer%C3%A1s
=======================================================================*/

#ifndef PROBLEMA_H_
#define PROBLEMA_H_

#include <iostream>
#include <utility>
#include <vector>

#include "Solucion.h"

class Problema {
 public:
  Problema() {}
  virtual ~Problema() {}

  virtual bool isCasoMinimo() {}
  virtual std::pair<Problema*, Problema*> descomponer() {}
  virtual void solver(Solucion* s) = 0;

 protected:
  std::vector<int> array_;
};

#endif /* PROBLEMA_H_ */
