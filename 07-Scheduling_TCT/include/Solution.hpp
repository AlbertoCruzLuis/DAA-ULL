#ifndef SOLUTION_H
#define SOLUTION_H

#include <iostream>
#include <vector>

#include "Graph.hpp"
#include "Machine.hpp"

class Solution {
 private:
  std::vector<Machine> list_machines_;

 public:
  Solution(int machine_numbers);
  ~Solution() {}

  std::vector<Machine> get_list_machines();

  void add_task(std::pair<int, int> task, int machine);
  int assigned_tasks();
  int calculate_objetive_function() const;
  std::pair<int, int> find_task_to_add(Graph& graph, int currentMachine);

  friend std::ostream& operator<<(std::ostream& os, const Solution& solution);
};
#endif  // SOLUTION_H