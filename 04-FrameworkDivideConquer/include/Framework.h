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

#ifndef FRAMEWORK_H_
#define FRAMEWORK_H_

#include <iostream>
#include <utility>
#include <vector>

#include "Problema.h"
#include "Solucion.h"

class Framework {
 public:
  Framework();
  virtual ~Framework();
  void divideyVenceras(Problema* p, Solucion* s);
};

#endif /* FRAMEWORK_H_ */
