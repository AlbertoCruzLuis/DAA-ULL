#ifndef SOLUTION_H
#define SOLUTION_H

#include <iostream>
#include <vector>

#include "Point.hpp"

class Solution {
 private:
  std::vector<Point> list_points_;

 public:
  Solution() {}
  ~Solution() {}

  void add_point(Point point);

  std::vector<Point> get_list_points() const;
  std::vector<Point>& get_list_points();

  float calculate_euclidean_distance(Point first, Point second) const;
  float calculate_objetive_function() const;

  friend std::ostream& operator<<(std::ostream& os, const Solution& solution);
};
#endif  // SOLUTION_H