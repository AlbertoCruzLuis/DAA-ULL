#ifndef GRASP_H
#define GRASP_H

#include <iostream>
#include <vector>

#include "Algorithm.hpp"
#include "NeighbourAlgorithm.hpp"
#include "Task.hpp"

class GRASP : public Algorithm {
 private:
  int MAX_ITERATIONS_ = 100;
  int SIZE_RCL = 3;
  NeighbourAlgorithm *neighbour_algorithm_;

 public:
  GRASP(NeighbourAlgorithm *neighbour_algorithm, int max_iterations = 100,
        int size_rcl = 3);
  virtual ~GRASP();
  Solution execute(Graph &graph);
  Solution greedy_randomized_construction(Graph &graph);
  std::vector<Task> build_RCL(Graph &graph, Solution &solution,
                              int current_machine, int size_rcl);
  Task select_random_candidate(std::vector<Task> rcl);
  int find_machine_min_tct(Solution solution);
};
#endif  // GRASP_H