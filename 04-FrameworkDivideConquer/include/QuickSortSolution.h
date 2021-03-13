#ifndef QUICKSORTSOLUTION_H
#define QUICKSORTSOLUTION_H

#include "Solucion.h"

class QuickSortSolution : public Solucion {
 private:
  /* data */
 public:
  QuickSortSolution();
  ~QuickSortSolution() {}

  void resolver();
  void mezcla(std::pair<Solucion*, Solucion*> subSolutions);
  Solucion* getInstance();
};

#endif  // QUICKSORTSOLUTION_H