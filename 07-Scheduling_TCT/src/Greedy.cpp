#include "Algorithms/Greedy.hpp"

#include <limits>

Solution Greedy::execute(Graph &graph) {
  std::cout << "\nGreedy execute" << std::endl;
  Solution solution(graph.get_machines_number());
  for (size_t i = 0; i < graph.get_machines_number(); i++) {
    solution.add_task(graph.min_values_of_arcs()[i], i);
  }

  int currentMachine = 0;
  do {
    // Obtener la tarea-maquina-posicion que minimiza el incremento del TCT
    Task task = solution.find_task_to_add(graph, currentMachine);

    solution.add_task(task, currentMachine);
    currentMachine = find_machine_min_tct(solution);

    // Insertarla en la posicion que corresponda y actualizar S*
  } while (solution.assigned_tasks() < graph.get_tasks_number());

  return solution;
}

int Greedy::find_machine_min_tct(Solution solution) {
  int index_of_current_machine = 0;
  int min_tct = std::numeric_limits<int>::max();
  Task machine_min_tct = Task(min_tct, index_of_current_machine);
  for (auto &&machine : solution.get_list_machines()) {
    int current_tct = machine.calculate_tct();
    if (current_tct < machine_min_tct.get_id_task()) {
      machine_min_tct.set_id_task(current_tct);
      machine_min_tct.set_value_of_arc(index_of_current_machine);
    }
    index_of_current_machine++;
  }
  return machine_min_tct.get_value_of_arc();
}
