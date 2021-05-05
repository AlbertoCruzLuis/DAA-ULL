#ifndef GRASP_H
#define GRASP_H

#include "Algorithm.hpp"
#include "NeighbourAlgorithms/NeighbourAlgorithm.hpp"

class GRASP : public Algorithm {
 private:
  NeighbourAlgorithm *neighbour_algorithm_;
  int size_solution_;
  int MAX_ITERATIONS_ = 100;
  int SIZE_RCL = 3;

 public:
  GRASP(int size_solution, NeighbourAlgorithm *neighbour_algorithm,
        int size_rcl = 3, int max_iterations = 100);
  virtual ~GRASP() {}

  Solution execute(Problem &problem);
  Solution greedy_randomized_construction(Problem &problem);
  std::vector<Point> build_RCL(Problem &problem, Solution &solution);
  Point select_random_candidate(std::vector<Point> rcl);
};
#endif  // GRASP_H