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

#ifndef MERGESORTPROBLEM_H
#define MERGESORTPROBLEM_H

#include "Problema.h"

class MergeSortProblem : public Problema {
 public:
  MergeSortProblem(std::vector<int> array);
  ~MergeSortProblem() {}

  bool isCasoMinimo();
  std::pair<Problema*, Problema*> descomponer();
  void solver(Solucion* s);
};

#endif  // MERGESORTPROBLEM_H