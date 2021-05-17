#include "Experiment.hpp"

#include <regex>

#include "Algorithms/BranchBound.hpp"
#include "Algorithms/GRASP.hpp"
#include "Algorithms/Greedy.hpp"
#include "Strategy.hpp"
#include "Timer/timer.cpp"

Experiment::Experiment(Problem problem, std::string type_algorithm) {
  problem_ = problem;
  type_algorithm_ = type_algorithm;
}

int Experiment::get_size_solution() const { return size_solution_; }

float Experiment::get_cpu_time() const { return cpu_time_; }

Solution Experiment::get_solution() const { return solution_; }

Solution& Experiment::get_solution() { return solution_; }

std::string Experiment::get_type_algorithm() const { return type_algorithm_; }

Problem Experiment::get_problem() const { return problem_; }

void Experiment::greedy(int size_solution) {
  type_algorithm_ = "greedy";
  size_solution_ = size_solution;

  cpu_time_ = timer([this, size_solution]() {
    Strategy strategy(new Greedy(size_solution));
    solution_ = strategy.run(problem_);
  });
}

void Experiment::grasp(int size_solution,
                       NeighbourAlgorithm* neighbourAlgorithm, int size_rcl,
                       int max_iterations) {
  type_algorithm_ = "grasp";
  size_solution_ = size_solution;
  max_iterations_ = max_iterations;
  rcl_size_ = size_rcl;

  cpu_time_ = timer(
      [this, size_solution, neighbourAlgorithm, size_rcl, max_iterations]() {
        Strategy strategy(new GRASP(size_solution, neighbourAlgorithm, size_rcl,
                                    max_iterations));
        solution_ = strategy.run(problem_);
      });
}

void Experiment::branch_bound(int size_solution, Solution solution,
                              int expansion_strategy) {
  type_algorithm_ = "branch_bound";
  size_solution_ = size_solution;
  expansion_strategy_ = expansion_strategy;

  cpu_time_ = timer([this, size_solution, solution, expansion_strategy]() {
    Strategy strategy(
        new BranchBound(size_solution, solution, expansion_strategy));
    solution_ = strategy.run(problem_);
  });
}

std::ostream& Experiment::show_table(std::ostream& os) {
  std::string problem_name = get_problem().get_file_name();
  problem_name = std::regex_replace(problem_name, std::regex("examples/"), "");

  os << "| " << problem_name << " | " << get_problem().get_points_size()
     << "  | " << get_problem().get_dimension_size() << "   | "
     << get_size_solution() << "   |";

  algorithm_extra_info(os);

  os << get_solution().calculate_objetive_function() << "  |";
  os << " [";
  for (auto&& point : get_solution().get_list_points()) {
    os << point.get_id() << " ";
  }
  os << "]  |" << get_cpu_time() << "ms |\n";
  return os;
}

void Experiment::header_extra_info(std::ostream& os) const {
  if (type_algorithm_ == "grasp") {
    os << "| Iter   | LRC  ";
  }
  if (type_algorithm_ == "branch_bound") {
    os << "| Strategy ";
  }
}

void Experiment::algorithm_extra_info(std::ostream& os) const {
  if (type_algorithm_ == "grasp") {
    os << max_iterations_ << "     |" << rcl_size_ << "    |";
  }
  if (type_algorithm_ == "branch_bound") {
    std::string name_strategy =
        expansion_strategy_ == 0 ? "Minimum Level" : "Deep";
    os << name_strategy << "  |";
  }
}

std::ostream& operator<<(std::ostream& os, const Experiment& experiment) {
  os << experiment.get_type_algorithm() << "\n";
  os << "| Problema"
     << "         ";
  os << "| n"
     << "   ";
  os << "| K"
     << "   ";
  os << "| m"
     << "   ";
  experiment.header_extra_info(os);
  os << "| z"
     << "       ";
  os << "| S"
     << "          ";
  os << "| CPU |\n";
  os << "|------------------|-----|-----|-----|--------|------|-------|"
        "--|----|---|";
  return os;
}
