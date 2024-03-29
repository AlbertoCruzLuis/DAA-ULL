#ifndef EXPERIMENT_H
#define EXPERIMENT_H

#include "Algorithms/GRASP.hpp"
#include "Algorithms/GVNS.hpp"
#include "Algorithms/Greedy.hpp"
#include "Algorithms/MultiBoot.hpp"
#include "Graph.hpp"
#include "NeighbourAlgorithms/ExchangeExternalMachine.hpp"
#include "NeighbourAlgorithms/NeighbourAlgorithm.hpp"
#include "NeighbourAlgorithms/ReinsertionExternalMachine.hpp"
#include "NeighbourAlgorithms/ReinsertionOwnMachine.hpp"
#include "TaskScheduler.hpp"

class Experiment {
 private:
  std::string type_algorithm_;
  std::string neighbour_algorithm_;
  int max_iterations_;
  int rcl_size_;
  int value_environmental_structure_;

 public:
  Experiment(Graph& graph, std::string type_algorithm = "greedy",
             std::string neighbour_algorithm = "ReinsertionOwnMachine",
             int max_iterations = 100, int rcl_size = 3,
             int value_environmental_structure = 5);
  ~Experiment() {}

  Algorithm* choose_algorithm(std::string type_algorithm,
                              std::string neighbour_algorithm);
  NeighbourAlgorithm* choose_neighbour_algorithm(std::string type_algorithm);
};
#endif  // EXPERIMENT_H