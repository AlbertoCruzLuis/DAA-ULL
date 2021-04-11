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

class Graph {
 private:
  std::vector<int> processing_times_;
  std::vector<std::vector<int>> setup_times_;
  int tasks_number_;
  int machines_number_;
  std::fstream file_;

  std::vector<int> nodes_;
  std::vector<int> arcs_;
  std::vector<std::vector<int>> value_of_arc;

 public:
  Graph(std::string file_name);
  ~Graph() {}

  void analyze_file();
  void parse_tasks();
  void parse_machines();
  void parse_processing_times();
  void parse_setup_times();
};
#endif  // GRAPH_H