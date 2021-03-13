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

#ifndef QUICKSORTPROBLEM_H
#define QUICKSORTPROBLEM_H

#include "Problema.h"

class QuickSortProblem : public Problema {
 private:
  /* data */
 public:
  QuickSortProblem(std::vector<int> array);
  ~QuickSortProblem() {}

  bool isCasoMinimo();
  std::pair<Problema *, Problema *> descomponer();
  void solver(Solucion *s);
  void swap(int &first, int &second);
};

#endif  // QUICKSORTPROBLEM_H