#ifndef PROBLEM_H
#define PROBLEM_H

#include <fstream>
#include <iostream>
#include <vector>

#include "Point.hpp"

class Problem {
 private:
  int points_size_;
  int dimension_size_;
  std::vector<Point> list_points_;
  std::fstream file_;

 public:
  Problem(std::string file_name);
  ~Problem() {}

  std::vector<Point> get_list_points() const;

  void analize_file();
  void parse_points_size();
  void parse_dimension_size();
  void parse_points();

  float calculate_euclidean_distance(Point first, Point second) const;
  Point calculate_center(std::vector<Point> points) const;

  friend std::ostream& operator<<(std::ostream& os, const Problem& problem);
};
#endif  // PROBLEM_H