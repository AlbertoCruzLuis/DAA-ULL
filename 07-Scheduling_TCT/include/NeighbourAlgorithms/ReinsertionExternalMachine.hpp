#ifndef REINSERTIONEXTERNALMACHINE_H
#define REINSERTIONEXTERNALMACHINE_H

#include "NeighbourAlgorithms/NeighbourAlgorithm.hpp"

class ReinsertionExternalMachine : public NeighbourAlgorithm {
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
    // std::cout << "----- Reinsertion ------" << std::endl;
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
                        solution.get_list_machines()[index_machine_two]);
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
      for (size_t i = 0; i < machine_two.get_processed_tasks().size() + 1;
           i++) {
        /*std::cout << "1 -<< " << solution.calculate_objetive_function()
                  << std::endl;*/
        if (machine_one.assigned_tasks() >= 1) {
          reinsertion(machine_one, machine_two, index_task_one, index_task_two);
        }
        /*std::cout << "2 -<< " << solution.calculate_objetive_function()
                  << std::endl;*/
        if (solution.calculate_objetive_function() <
            best_solution.calculate_objetive_function()) {
          best_solution = solution;
        }
      }
    }

    /*if (index_task_one < machine_one.get_processed_tasks().size()) {
      if (index_task_two < machine_two.get_processed_tasks().size() + 1) {
        reinsertion(machine_one, machine_two, index_task_one, index_task_two);
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

  void reinsertion(Machine& machine_origin, Machine& machine_destination,
                   int origin, int destination) {
    Task task_to_insert = machine_origin.get_processed_tasks()[origin];
    machine_destination.insert_task(destination, task_to_insert);
    machine_origin.erase_task(origin);
  }
};
#endif  // REINSERTIONEXTERNALMACHINE_H