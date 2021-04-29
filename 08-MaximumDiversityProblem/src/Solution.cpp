#include "Solution.hpp"

#include <cmath>

std::vector<Point> Solution::get_list_points() const { return list_points_; }

void Solution::add_point(Point point) { list_points_.push_back(point); }

float Solution::calculate_objetive_function() const {
  float objetive_function = 0;
  for (size_t i = 0; i < list_points_.size(); i++) {
    for (size_t j = i + 1; j < list_points_.size(); j++) {
      objetive_function +=
          calculate_euclidean_distance(list_points_[i], list_points_[j]);
    }
  }

  return objetive_function;
}

Point Solution::calculate_center(std::vector<Point> points) const {
  Point center;
  int dimension_size = points[0].get_coordinates().size();

  for (int j = 0; j < dimension_size; j++) {
    float sum = 0;
    for (int i = 0; i < points.size(); i++) {
      sum += points[i].get_coordinates()[j];
    }
    float coordinate = sum / points.size();
    center.add_coordinate(coordinate);
  }
  return center;
}

float Solution::calculate_euclidean_distance(Point first, Point second) const {
  float distance = 0;
  int dimension_size = first.get_coordinates().size();
  for (size_t i = 0; i < dimension_size; i++) {
    distance +=
        std::pow((first.get_coordinates()[i] - second.get_coordinates()[i]), 2);
  }
  distance = std::sqrt(distance);
  return distance;
}

std::ostream& operator<<(std::ostream& os, const Solution& solution) {
  for (auto&& point : solution.get_list_points()) {
    os << point;
  }
  os << "\n";
  return os;
}
