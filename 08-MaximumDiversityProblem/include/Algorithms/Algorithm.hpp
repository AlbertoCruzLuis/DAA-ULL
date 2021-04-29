#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "Problem.hpp"
#include "Solution.hpp"

class Algorithm {
 public:
  virtual Solution execute(Problem &problem) = 0;
};
#endif  // ALGORITHM_H