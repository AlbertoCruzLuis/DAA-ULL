#ifndef GREEDY_H
#define GREEDY_H

#include <iostream>

#include "Algorithm.hpp"

class Greedy : public Algorithm {
 public:
  Solution execute(Graph &graph);
  int find_machine_min_tct(Solution solution);
};
#endif  // GREEDY_H