#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "Graph.hpp"
#include "Solution.hpp"

class Algorithm {
 public:
  virtual Solution execute(Graph &graph) = 0;
};
#endif  // ALGORITHM_H