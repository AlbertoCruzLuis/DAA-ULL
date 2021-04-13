#ifndef MACHINE_H
#define MACHINE_H

#include <iostream>
#include <vector>

#include "Graph.hpp"
#include "Task.hpp"

class Machine {
 private:
  std::vector<Task> processed_tasks_;
  int tct_;  // total completion time

 public:
  Machine(/* args */) {}
  ~Machine() {}

  std::vector<Task> get_processed_tasks();
  void add_task(Task task);
  int assigned_tasks();
  int calculate_tct() const;

  friend std::ostream& operator<<(std::ostream& os, const Machine& machine);
};
#endif  // MACHINE_H