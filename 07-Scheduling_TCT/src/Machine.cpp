#include "Machine.hpp"

void Machine::add_task(Task task) { processed_tasks_.push_back(task); }

void Machine::insert_task(int position, Task task) {
  processed_tasks_.insert(processed_tasks_.begin() + position, task);
}

void Machine::erase_task(int position) {
  processed_tasks_.erase(processed_tasks_.begin() + position);
}

std::vector<Task> Machine::get_processed_tasks() const {
  return processed_tasks_;
}

void Machine::set_processed_task(std::vector<Task> processed_task) {
  processed_tasks_ = processed_task;
}

int Machine::assigned_tasks() { return processed_tasks_.size(); }

int Machine::calculate_tct() const {
  int tct = 0;
  for (size_t i = 1; i <= processed_tasks_.size(); i++) {
    int sum = 0;
    for (size_t j = 0; j < i; j++) {
      sum += processed_tasks_[j].get_value_of_arc();
    }
    tct += sum;
  }
  return tct;

  /*int tct = 0;
  int id_task;
  for (size_t i = 1; i < list_machines.size(); i++) {
    for (size_t j = 1; j < list_machines[i].processed_tasks_.size(); j++) {
      tct += (list_machines[i].processed_tasks_.size() - j + 1) *
             values_of_arcs[j - 1][j].second;
      id_task = values_of_arcs[j - 1][j].first;
    }
  }
  std::cout << "Task: " << id_task << " TCT: " << tct << std::endl;*/
}

std::ostream& operator<<(std::ostream& os, const Machine& machine) {
  for (auto&& task : machine.processed_tasks_) {
    os << task.get_id_task() << " ";
  }
  os << "TCT: " << machine.calculate_tct();

  return os;
}
