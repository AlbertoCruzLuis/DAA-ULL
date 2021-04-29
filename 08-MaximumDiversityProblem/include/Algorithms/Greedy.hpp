#ifndef GREEDY_H
#define GREEDY_H

#include "Algorithm.hpp"

class Greedy : public Algorithm {
  int size_solution_;

 public:
  Greedy(int size_solution);
  Solution execute(Problem &problem);
  Point furthest_of_center(Point center, std::vector<Point> points);
  void erase_point(Point point_to_erase, std::vector<Point> &points);
};
#endif  // GREEDY_H