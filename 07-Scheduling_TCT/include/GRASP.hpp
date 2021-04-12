#ifndef GRASP_H
#define GRASP_H

#include <iostream>

#include "Algorithm.hpp"

class GRASP : public Algorithm {
 public:
  Solution execute(Graph &graph);
};
#endif  // GRASP_H