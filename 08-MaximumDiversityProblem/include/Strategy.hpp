#ifndef STRATEGY_H
#define STRATEGY_H

#include "Algorithms/Algorithm.hpp"
#include "Solution.hpp"

class Strategy {
 private:
  Algorithm* algorithm_;

 public:
  Strategy(Algorithm* algorithm) { algorithm_ = algorithm; }
  ~Strategy() {}

  Solution run(Problem problem) { return algorithm_->execute(problem); }
};
#endif  // STRATEGY_H