#ifndef MULTIBOOT_H
#define MULTIBOOT_H

#include "Algorithm.hpp"
#include "NeighbourAlgorithm.hpp"

class MultiBoot : public Algorithm {
 private:
  int MAX_ITERATIONS_ = 100;
  NeighbourAlgorithm *neighbour_algorithm_;

 public:
  MultiBoot(NeighbourAlgorithm *neighbour_algorithm, int max_iterations = 100);
  virtual ~MultiBoot();
  Solution execute(Graph &graph);
  Solution generate_boot_solution(Graph &graph);
};
#endif  // MULTIBOOT_H