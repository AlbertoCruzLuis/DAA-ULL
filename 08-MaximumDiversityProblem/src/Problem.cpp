#include "Problem.hpp"

#include <algorithm>
#include <cmath>
#include <sstream>

Problem::Problem(std::string file_name) {
  file_.open(file_name, std::fstream::in);
  file_name_ = file_name;
  analize_file();
}

Problem::Problem(const Problem& problem) {
  points_size_ = problem.points_size_;
  dimension_size_ = problem.dimension_size_;
  list_points_ = problem.list_points_;
  file_name_ = problem.file_name_;
}

std::string Problem::get_file_name() const { return file_name_; }

int Problem::get_points_size() const { return points_size_; }

int Problem::get_dimension_size() const { return dimension_size_; }

std::vector<Point> Problem::get_list_points() const { return list_points_; }

void Problem::analize_file() {
  parse_points_size();
  parse_dimension_size();
  parse_points();
}

void Problem::parse_points_size() {
  std::string line;
  getline(file_ >> std::ws, line);
  points_size_ = std::stoi(line);
}

void Problem::parse_dimension_size() {
  std::string line;
  getline(file_ >> std::ws, line);
  dimension_size_ = std::stoi(line);
}

void Problem::parse_points() {
  std::string line;
  int point_id = 0;
  while (getline(file_ >> std::ws, line)) {
    std::istringstream iss(line);
    std::string coordinate_value;
    Point point(point_id);
    while (iss >> coordinate_value) {
      std::replace(coordinate_value.begin(), coordinate_value.end(), ',', '.');
      point.add_coordinate(std::stof(coordinate_value));
    }
    list_points_.push_back(point);
    point_id++;
  }
}

float Problem::calculate_euclidean_distance(Point first, Point second) const {
  float distance = 0;
  int dimension_size = first.get_coordinates().size();
  for (size_t i = 0; i < dimension_size; i++) {
    distance +=
        std::pow((first.get_coordinates()[i] - second.get_coordinates()[i]), 2);
  }
  distance = std::sqrt(distance);
  return distance;
}

Point Problem::calculate_center(std::vector<Point> points) const {
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

Problem& Problem::operator=(const Problem& problem) {
  points_size_ = problem.points_size_;
  dimension_size_ = problem.dimension_size_;
  list_points_ = problem.list_points_;
  file_name_ = problem.file_name_;
}

std::ostream& operator<<(std::ostream& os, const Problem& problem) {
  os << problem.points_size_ << "\n";
  os << problem.dimension_size_ << "\n";
  for (auto&& point : problem.list_points_) {
    os << point;
  }
  return os;
}
