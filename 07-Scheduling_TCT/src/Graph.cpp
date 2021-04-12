#include "Graph.hpp"

#include <algorithm>
#include <sstream>

Graph::Graph(std::string file_name) {
  file_.open(file_name, std::fstream::in);

  analyze_file();
  values_of_arcs_.resize(tasks_number_ + 1,
                         std::vector<std::pair<int, int>>(tasks_number_ + 1));
  calculate_values_of_arcs();
}

int Graph::get_tasks_number() { return tasks_number_; }

int Graph::get_machines_number() { return machines_number_; }

std::vector<std::vector<std::pair<int, int>>> Graph::get_values_of_arcs() {
  return values_of_arcs_;
}

void Graph::analyze_file() {
  parse_tasks();
  parse_machines();
  parse_processing_times();
  parse_setup_times();
}

void Graph::parse_tasks() {
  std::string line;
  getline(file_ >> std::ws, line);
  std::istringstream iss(line);
  std::string id, task_number;

  iss >> id;
  iss >> task_number;
  tasks_number_ = std::stoi(task_number);
}

void Graph::parse_machines() {
  std::string line;
  getline(file_ >> std::ws, line);
  std::istringstream iss(line);
  std::string id, machine_number;

  iss >> id;
  iss >> machine_number;
  machines_number_ = std::stoi(machine_number);
}

void Graph::parse_processing_times() {
  std::string line;
  getline(file_ >> std::ws, line);
  std::istringstream iss(line);
  std::string id, processing_time;
  iss >> id;
  processing_times_.push_back(0);
  while (iss >> processing_time) {
    processing_times_.push_back(std::stoi(processing_time));
  }
}

void Graph::parse_setup_times() {
  std::string line;
  getline(file_ >> std::ws, line);
  while (getline(file_ >> std::ws, line)) {
    std::istringstream iss(line);
    std::string setup_time;
    std::vector<int> line_setup_time;
    while (iss >> setup_time) {
      line_setup_time.push_back(std::stoi(setup_time));
    }
    setup_times_.push_back(line_setup_time);
  }
}

void Graph::calculate_values_of_arcs() {
  for (size_t i = 0; i < setup_times_.size(); i++) {
    for (size_t j = 0; j < processing_times_.size(); j++) {
      values_of_arcs_[i][j] =
          std::make_pair(j, setup_times_[i][j] + processing_times_[j]);
    }
  }
}

std::vector<std::pair<int, int>> Graph::min_values_of_arcs() {
  std::vector<std::pair<int, int>> temp_values_of_arcs = values_of_arcs_[0];

  std::sort(
      temp_values_of_arcs.begin(), temp_values_of_arcs.end(),
      [](std::pair<int, int> before_value, std::pair<int, int> after_value) {
        if (after_value.first != 0) {
          return before_value.second < after_value.second;
        } else {
          return true;
        }
      });
  std::vector<std::pair<int, int>> min_top_values;
  for (size_t i = 0; i < machines_number_; i++) {
    min_top_values.push_back(temp_values_of_arcs[i]);
  }
  return min_top_values;
}

std::pair<int, int> Graph::min_element_of_row(
    std::vector<std::pair<int, int>> proccessed_task,
    int index_last_proccessed_task) {
  std::vector<std::pair<int, int>> list_element_to_search;

  std::copy_if(values_of_arcs_[index_last_proccessed_task].begin(),
               values_of_arcs_[index_last_proccessed_task].end(),
               std::back_inserter(list_element_to_search),
               [proccessed_task](std::pair<int, int> task) {
                 for (auto &&proccess_task : proccessed_task) {
                   if (proccess_task.first == task.first || task.first == 0) {
                     return false;
                   }
                 }
                 return true;
               });

  return *std::min_element(
      list_element_to_search.begin(), list_element_to_search.end(),
      [](std::pair<int, int> before_task, std::pair<int, int> after_task) {
        return before_task.second < after_task.second;
      });
}
