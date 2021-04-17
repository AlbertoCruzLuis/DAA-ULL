#include "Task.hpp"

Task::Task(int id_task, int value_of_arc)
    : id_task_(id_task), value_of_arc_(value_of_arc) {}

int Task::get_id_task() const { return id_task_; }

int Task::get_value_of_arc() const { return value_of_arc_; }

void Task::set_id_task(int id_task) { id_task_ = id_task; }

void Task::set_value_of_arc(int value_of_arc) { value_of_arc_ = value_of_arc; }

/*Task& Task::operator=(const Task& task) {
  if (this != &task) {
    std::copy(&task.id_task_, &task.id_task_, &id_task_);
    std::copy(&task.value_of_arc_, &task.value_of_arc_, &value_of_arc_);
  }
  return *this;
}*/

bool operator==(const Task& task, const Task& other_task) {
  return task.get_id_task() == other_task.get_id_task();
}
