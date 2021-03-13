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

#ifndef MERGESORTSOLUTION_H
#define MERGESORTSOLUTION_H

#include "Solucion.h"

class MergeSortSolution : public Solucion {
 public:
  MergeSortSolution();
  ~MergeSortSolution() {}

  void resolver();
  void mezcla(std::pair<Solucion*, Solucion*> subSolutions);
  Solucion* getInstance();
};

#endif  // MERGESORTSOLUTION_H