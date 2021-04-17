#ifndef TASK_H
#define TASK_H

#include <iostream>

class Task {
 private:
  int id_task_;
  int value_of_arc_;

 public:
  Task() {}
  Task(int id_task, int value_of_arc);
  ~Task() {}

  int get_id_task() const;
  int get_value_of_arc() const;

  void set_id_task(int id_task);
  void set_value_of_arc(int value_of_arc);

  // Task& operator=(const Task& task);

  friend bool operator==(const Task& task, const Task& other_task);
};
#endif  // TASK_H