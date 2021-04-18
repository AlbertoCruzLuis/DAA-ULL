#ifndef NEIGHBOURALGORITHM_H
#define NEIGHBOURALGORITHM_H

#include <algorithm>

#include "Solution.hpp"

class NeighbourAlgorithm {
 protected:
  Solution solution_to_swap;
  std::vector<std::vector<Task>> processed_task;
  int index_solution_ = 0;

 public:
  virtual Solution execute(Solution& solution) = 0;
  void set_solution_to_swap(Solution solution) {
    solution_to_swap = solution;
    for (auto&& machine : solution.get_list_machines()) {
      processed_task.push_back(machine.get_processed_tasks());
    }
  }
};

class ExchangeOwnMachine : public NeighbourAlgorithm {
  Solution execute(Solution& solution) {
    index_solution_ =
        (index_solution_ + 1) % solution.get_list_machines().size();
    check_is_permutation(solution, index_solution_);

    std::next_permutation(
        processed_task[index_solution_].begin(),
        processed_task[index_solution_].end(), [](Task first, Task second) {
          return first.get_value_of_arc() < second.get_value_of_arc();
        });

    solution.set_proccessed_tasks(index_solution_,
                                  processed_task[index_solution_]);

    return solution;
  }
  void check_is_permutation(Solution solution, int index_solution) {
    std::vector<Task> solution_processed_task =
        solution.get_list_machines()[index_solution_].get_processed_tasks();

    std::vector<Task> neighbour_processed_task =
        solution_to_swap.get_list_machines()[index_solution_]
            .get_processed_tasks();
    bool is_permutation = std::is_permutation(
        solution_processed_task.begin(), solution_processed_task.end(),
        neighbour_processed_task.begin(), neighbour_processed_task.end());
    if (!is_permutation) {
      solution_to_swap = solution;
      std::vector<std::vector<Task>> new_processed_task;
      for (auto&& machine : solution.get_list_machines()) {
        new_processed_task.push_back(machine.get_processed_tasks());
      }
      processed_task = new_processed_task;
    }
  }
};

#endif  // NEIGHBOURALGORITHM_H