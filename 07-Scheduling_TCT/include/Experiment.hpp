#ifndef EXPERIMENT_H
#define EXPERIMENT_H

#include "ExchangeExternalMachine.hpp"
#include "GRASP.hpp"
#include "Graph.hpp"
#include "Greedy.hpp"
#include "MultiBoot.hpp"
#include "NeighbourAlgorithm.hpp"
#include "ReinsertionExternalMachine.hpp"
#include "ReinsertionOwnMachine.hpp"
#include "TaskScheduler.hpp"

class Experiment {
 private:
  std::string type_algorithm_;
  std::string neighbour_algorithm_;
  int max_iterations_;
  int rcl_size_;

 public:
  Experiment(Graph& graph, std::string type_algorithm = "greedy",
             std::string neighbour_algorithm = "ReinsertionOwnMachine",
             int max_iterations = 100, int rcl_size = 3);
  ~Experiment() {}

  Algorithm* choose_algorithm(std::string type_algorithm,
                              std::string neighbour_algorithm);
  NeighbourAlgorithm* choose_neighbour_algorithm(std::string type_algorithm);
};
#endif  // EXPERIMENT_H