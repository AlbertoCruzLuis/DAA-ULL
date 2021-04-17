#ifndef SOLUTION_H
#define SOLUTION_H

#include <iostream>
#include <vector>

#include "Graph.hpp"
#include "Machine.hpp"
#include "Task.hpp"

class Solution {
 private:
  std::vector<Machine> list_machines_;

 public:
  Solution() {}
  Solution(int machine_numbers);
  ~Solution() {}

  std::vector<Machine> get_list_machines() const;
  std::vector<Machine>& get_list_machines();
  void set_proccessed_tasks(int machine, std::vector<Task> proccessed_tasks);

  void add_task(Task task, int machine);
  int get_index_last_proccessed_task(int current_machine);
  int assigned_tasks();
  int calculate_objetive_function() const;
  Task find_task_to_add(Graph& graph, int currentMachine);
  std::vector<Task> all_proccessed_tasks();

  friend std::ostream& operator<<(std::ostream& os, const Solution& solution);
};
#endif  // SOLUTION_H