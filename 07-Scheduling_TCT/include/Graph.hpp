/*=======================================================================
|| @Author: Alberto Cruz Luis
|| @Email: alu0101217734@ull.edu.es
|| @Github: https://github.com/AlbertoCruzLuis
|| @Date: April 2021
|| @University: ULL in Tenerife
|| @Course: DAA
|| @Version: 07-Scheduling_TCT
|| @Info: https://en.wikipedia.org/wiki/Parallel_task_scheduling_problem
=======================================================================*/

#ifndef GRAPH_H
#define GRAPH_H

#include <fstream>
#include <iostream>
#include <vector>

#include "Task.hpp"

class Graph {
 private:
  std::vector<int> processing_times_;
  std::vector<std::vector<int>> setup_times_;
  int tasks_number_;
  int machines_number_;
  std::fstream file_;

  std::vector<std::vector<Task>> values_of_arcs_;

 public:
  Graph(std::string file_name);
  ~Graph() {}

  int get_tasks_number();
  int get_machines_number();
  std::vector<std::vector<Task>> get_values_of_arcs();

  void analyze_file();
  void parse_tasks();
  void parse_machines();
  void parse_processing_times();
  void parse_setup_times();

  void calculate_values_of_arcs();
  std::vector<Task> min_values_of_arcs();
  std::vector<Task> unprocessed_tasks(std::vector<Task> proccessed_task,
                                      int index_last_proccessed_task);
  Task min_element_of_row(std::vector<Task> proccessed_task,
                          int index_last_proccessed_task);
};
#endif  // GRAPH_H