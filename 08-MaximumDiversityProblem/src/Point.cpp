#include "Point.hpp"

#include <cmath>

void Point::add_coordinate(float coordinate_value) {
  coordinates_.push_back(coordinate_value);
}

std::vector<float> Point::get_coordinates() const { return coordinates_; }

int Point::get_id() const { return id_; }

void Point::set_id(int id) { id_ = id; }

float Point::calculate_euclidean_distance(Point first, Point second) const {
  float distance = 0;
  int dimension_size = first.get_coordinates().size();
  for (size_t i = 0; i < dimension_size; i++) {
    distance +=
        std::pow((first.get_coordinates()[i] - second.get_coordinates()[i]), 2);
  }
  distance = std::sqrt(distance);
  return distance;
}

std::ostream& operator<<(std::ostream& os, const Point& point) {
  os << "Id:" << point.get_id() << " | ";
  for (auto&& coordinate : point.get_coordinates()) {
    os << coordinate << " ";
  }
  os << "\n";

  return os;
}

Point::Point(int id) { id_ = id; }
