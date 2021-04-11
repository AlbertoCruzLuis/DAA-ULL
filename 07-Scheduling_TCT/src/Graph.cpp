#include "Graph.hpp"

#include <sstream>

Graph::Graph(std::string file_name) {
  file_.open(file_name, std::fstream::in);

  analyze_file();
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
