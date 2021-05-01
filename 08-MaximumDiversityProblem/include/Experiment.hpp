#ifndef EXPERIMENT_H
#define EXPERIMENT_H

#include <iostream>

#include "Problem.hpp"
#include "Solution.hpp"

class Experiment {
 private:
  std::string type_algorithm_;
  Problem problem_;
  Solution solution_;
  int size_solution_;
  float cpu_time_;

 public:
  Experiment(Problem problem, std::string type_algorithm);
  ~Experiment() {}

  int get_size_solution() const;
  float get_cpu_time() const;
  Solution get_solution() const;
  Solution& get_solution();
  std::string get_type_algorithm() const;
  Problem get_problem() const;

  void greedy(int size_solution);
  std::ostream& show_table(std::ostream& os);
  void algorithm_extra_info(std::ostream& os) const;
  void header_extra_info(std::ostream& os) const;

  friend std::ostream& operator<<(std::ostream& os,
                                  const Experiment& experiment);
};
#endif  // EXPERIMENT_H