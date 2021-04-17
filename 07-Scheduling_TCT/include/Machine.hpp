#ifndef MACHINE_H
#define MACHINE_H

#include <iostream>
#include <vector>

#include "Graph.hpp"
#include "Task.hpp"

class Machine {
 private:
  std::vector<Task> processed_tasks_;

 public:
  Machine(/* args */) {}
  ~Machine() {}

  std::vector<Task> get_processed_tasks() const;
  void set_processed_task(std::vector<Task> processed_task);
  void add_task(Task task);
  void insert_task(int position, Task task);
  void erase_task(int position);
  int assigned_tasks();
  int calculate_tct() const;

  friend std::ostream& operator<<(std::ostream& os, const Machine& machine);
};
#endif  // MACHINE_H