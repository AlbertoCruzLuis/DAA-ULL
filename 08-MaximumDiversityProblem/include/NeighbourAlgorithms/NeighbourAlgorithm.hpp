#ifndef NEIGHBOURALGORITHM_H
#define NEIGHBOURALGORITHM_H

#include <vector>

#include "Solution.hpp"

class NeighbourAlgorithm {
 public:
  virtual std::vector<Solution> generateNeighbour(Solution& solution) = 0;
};
#endif  // NEIGHBOURALGORITHM_H