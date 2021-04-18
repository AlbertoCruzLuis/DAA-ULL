#ifndef REINSERTIONOWNMACHINE_H
#define REINSERTIONOWNMACHINE_H

#include "NeighbourAlgorithms/NeighbourAlgorithm.hpp"

class ReinsertionOwnMachine : public NeighbourAlgorithm {
  int index_one = 0;
  int index_two = 0;
  int current_machine_index = 0;
  Solution execute(Solution& solution) {
    if (index_one < solution.get_list_machines()[current_machine_index]
                        .get_processed_tasks()
                        .size()) {
      if (index_two < solution.get_list_machines()[current_machine_index]
                          .get_processed_tasks()
                          .size()) {
        if (index_one != index_two) {
          reinsertion(solution, index_one, index_two);
        }
        index_two++;
      } else {
        index_one++;
        index_two = 0;
      }
    } else {
      index_one = 0;
      index_two = 0;
      current_machine_index =
          (current_machine_index + 1) % solution.get_list_machines().size();
    }
    return solution;
  }

  void reinsertion(Solution& solution, int origin, int destination) {
    int current_index = origin;
    while (current_index + 1 <= destination) {
      std::swap(solution.get_list_machines()[current_machine_index]
                    .get_processed_tasks()[current_index],
                solution.get_list_machines()[current_machine_index]
                    .get_processed_tasks()[current_index + 1]);
      current_index++;
    }
    while (current_index - 1 >= destination) {
      std::swap(solution.get_list_machines()[current_machine_index]
                    .get_processed_tasks()[current_index],
                solution.get_list_machines()[current_machine_index]
                    .get_processed_tasks()[current_index - 1]);
      current_index--;
    }
  }
};
#endif  // REINSERTIONOWNMACHINE_H