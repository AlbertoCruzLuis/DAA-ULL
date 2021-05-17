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
  std::string file_name_;

 public:
  Problem() {}
  Problem(const Problem& problem);
  Problem(std::string file_name);
  ~Problem() {}

  std::string get_file_name() const;
  int get_points_size() const;
  int get_dimension_size() const;
  std::vector<Point> get_list_points() const;
  Point get_point(int id);

  void analize_file();
  void parse_points_size();
  void parse_dimension_size();
  void parse_points();

  std::vector<Point> unproccessed_points(std::vector<Point> proccessed_points);

  float calculate_euclidean_distance(Point first, Point second) const;
  Point calculate_center(std::vector<Point> points) const;

  Problem& operator=(const Problem& problem);

  friend std::ostream& operator<<(std::ostream& os, const Problem& problem);
};
#endif  // PROBLEM_H