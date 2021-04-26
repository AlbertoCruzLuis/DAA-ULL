#ifndef EXCHANGEEXTERNALMACHINE_H
#define EXCHANGEEXTERNALMACHINE_H

#include "NeighbourAlgorithms/NeighbourAlgorithm.hpp"

class ExchangeExternalMachine : public NeighbourAlgorithm {
  int index_machine_one = 0;
  int index_machine_two = 1;
  int index_task_one = 0;
  int index_task_two = 0;
  Solution execute(Solution solution) {
    permutationMachine(solution);
    return solution;
  }
  void permutationMachine(Solution& solution) {
    Solution best_solution = solution;
    // std::cout << "----- Exchange ------" << std::endl;
    for (size_t i = 0; i < solution.get_list_machines().size(); i++) {
      for (size_t j = i + 1; j < solution.get_list_machines().size(); j++) {
        permutationTask(solution.get_list_machines()[index_machine_one],
                        solution.get_list_machines()[index_machine_two],
                        solution, best_solution);
      }
    }
    solution = best_solution;

    /*if (index_machine_one < solution.get_list_machines().size()) {
      if (index_machine_two < solution.get_list_machines().size()) {
        permutationTask(solution.get_list_machines()[index_machine_one],
                        solution.get_list_machines()[index_machine_two],
                        solution);
        index_machine_two++;
      } else {
        index_machine_one++;
        index_machine_two = index_machine_one + 1;
      }
    } else {
      index_machine_one = 0;
      index_machine_two = 1;
    }*/
  }
  void permutationTask(Machine& machine_one, Machine& machine_two,
                       Solution& solution, Solution& best_solution) {
    for (size_t i = 0; i < machine_one.get_processed_tasks().size(); i++) {
      for (size_t j = 0; j < machine_two.get_processed_tasks().size(); j++) {
        std::swap(machine_one.get_processed_tasks()[i],
                  machine_two.get_processed_tasks()[j]);
        // std::cout << "1 -<< " << solution << std::endl;
        if (solution.calculate_objetive_function() <
            best_solution.calculate_objetive_function()) {
          best_solution = solution;
        }
      }
    }

    /*if (index_task_one < machine_one.get_processed_tasks().size()) {
      if (index_task_two < machine_two.get_processed_tasks().size()) {
        std::swap(machine_one.get_processed_tasks()[index_task_one],
                  machine_two.get_processed_tasks()[index_task_two]);

        index_task_two++;
      } else {
        index_task_one++;
        index_task_two = 0;
      }
    } else {
      index_task_one = 0;
      index_task_two = 0;
    }*/
  }
};
#endif  // EXCHANGEEXTERNALMACHINE_H