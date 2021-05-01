#ifndef GRASP_H
#define GRASP_H

#include "Algorithm.hpp"
#include "NeighbourAlgorithms/NeighbourAlgorithm.hpp"

class GRASP : public Algorithm {
 private:
  NeighbourAlgorithm *neighbour_algorithm_;

 public:
  GRASP(NeighbourAlgorithm *neighbour_algorithm) {}
  virtual ~GRASP() {}

  Solution execute(Problem &problem);
};
#endif  // GRASP_H