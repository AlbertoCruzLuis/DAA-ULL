#ifndef MACHINE_H
#define MACHINE_H

#include <iostream>
#include <vector>

#include "Graph.hpp"

class Machine {
 private:
  std::vector<std::pair<int, int>> processed_tasks_;
  int tct_;  // total completion time

 public:
  Machine(/* args */) {}
  ~Machine() {}

  std::vector<std::pair<int, int>> get_processed_tasks();
  void add_task(std::pair<int, int> task);
  int assigned_tasks();
  int calculate_tct() const;

  friend std::ostream& operator<<(std::ostream& os, const Machine& machine);
};
#endif  // MACHINE_H