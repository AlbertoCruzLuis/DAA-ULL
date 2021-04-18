#ifndef REINSERTIONEXTERNALMACHINE_H
#define REINSERTIONEXTERNALMACHINE_H

#include "NeighbourAlgorithms/NeighbourAlgorithm.hpp"

class ReinsertionExternalMachine : public NeighbourAlgorithm {
  int index_machine_one = 0;
  int index_machine_two = 1;
  int index_task_one = 0;
  int index_task_two = 0;
  Solution execute(Solution& solution) {
    permutationMachine(solution);
    return solution;
  }

  void permutationMachine(Solution& solution) {
    if (index_machine_one < solution.get_list_machines().size()) {
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
    }
  }
  void permutationTask(Machine& machine_one, Machine& machine_two) {
    if (index_task_one < machine_one.get_processed_tasks().size()) {
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
    }
  }

  void reinsertion(Machine& machine_origin, Machine& machine_destination,
                   int origin, int destination) {
    Task task_to_insert = machine_origin.get_processed_tasks()[origin];
    machine_destination.insert_task(destination, task_to_insert);
    machine_origin.erase_task(origin);
  }
};
#endif  // REINSERTIONEXTERNALMACHINE_H