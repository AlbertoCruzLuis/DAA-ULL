#include "Algorithms/Greedy.hpp"

#include <algorithm>

Greedy::Greedy(int size_solution) { size_solution_ = size_solution; }

Solution Greedy::execute(Problem &problem) {
  std::vector<Point> points = problem.get_list_points();
  Solution solution;
  Point center = problem.calculate_center(points);
  do {
    Point point_furthest_of_center = furthest_of_center(center, points);
    solution.add_point(point_furthest_of_center);
    erase_point(point_furthest_of_center, points);
    center = problem.calculate_center(solution.get_list_points());
  } while (solution.get_list_points().size() < size_solution_);
  return solution;
}

Point Greedy::furthest_of_center(Point center, std::vector<Point> points) {
  Point furthest;
  float max_distance = 0;

  for (auto &&point : points) {
    float distance_fursthest_to_point =
        center.calculate_euclidean_distance(center, point);
    if (distance_fursthest_to_point > max_distance) {
      max_distance = distance_fursthest_to_point;
      furthest = point;
    }
  }
  return furthest;
}

void Greedy::erase_point(Point point_to_erase, std::vector<Point> &points) {
  for (auto &&point : points) {
    points.erase(std::remove_if(points.begin(), points.end(),
                                [point_to_erase](Point point) {
                                  return point.get_id() ==
                                         point_to_erase.get_id();
                                }),
                 points.end());
  }
}
