#include "Solution.hpp"

Solution::Solution(int machine_numbers) {
  list_machines_.resize(machine_numbers);
}

std::vector<Machine> Solution::get_list_machines() const {
  return list_machines_;
}

std::vector<Machine>& Solution::get_list_machines() { return list_machines_; }

void Solution::set_proccessed_tasks(int machine,
                                    std::vector<Task> proccessed_tasks) {
  list_machines_[machine].set_processed_task(proccessed_tasks);
}

void Solution::add_task(Task task, int machine) {
  list_machines_[machine].add_task(task);
}

int Solution::get_index_last_proccessed_task(int current_machine) {
  if (list_machines_[current_machine].get_processed_tasks().size() == 0) {
    return 0;
  }

  return list_machines_[current_machine]
      .get_processed_tasks()
          [list_machines_[current_machine].get_processed_tasks().size() - 1]
      .get_id_task();
}

int Solution::assigned_tasks() {
  int assigned_tasks = 0;
  for (auto&& machine : list_machines_) {
    assigned_tasks += machine.assigned_tasks();
  }
  return assigned_tasks;
}

int Solution::calculate_objetive_function() const {
  int objetive_function = 0;
  for (auto&& machine : list_machines_) {
    objetive_function += machine.calculate_tct();
  }
  return objetive_function;
}

Task Solution::find_task_to_add(Graph& graph, int current_machine) {
  std::vector<Task> list_all_proccessed_tasks = all_proccessed_tasks();
  int index_last_proccessed_task =
      get_index_last_proccessed_task(current_machine);

  return graph.min_element_of_row(list_all_proccessed_tasks,
                                  index_last_proccessed_task);
}

std::vector<Task> Solution::all_proccessed_tasks() {
  std::vector<Task> all_proccessed_tasks;
  for (auto&& machine : list_machines_) {
    for (auto&& task : machine.get_processed_tasks()) {
      all_proccessed_tasks.push_back(task);
    }
  }
  return all_proccessed_tasks;
}

std::ostream& operator<<(std::ostream& os, const Solution& solution) {
  int index_machine = 0;
  for (auto&& machine : solution.list_machines_) {
    os << "M[" << index_machine << "]: " << machine << "\n";
    index_machine++;
  }
  os << "Objetive Function: " << solution.calculate_objetive_function();

  return os;
}
