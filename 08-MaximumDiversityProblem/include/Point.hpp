#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <vector>

class Point {
 private:
  int id_;
  std::vector<float> coordinates_;

 public:
  Point() {}
  Point(int id);
  ~Point() {}

  void add_coordinate(float coordinate_value);

  std::vector<float> get_coordinates() const;
  int get_id() const;

  void set_id(int id);

  float calculate_euclidean_distance(Point first, Point second) const;

  friend std::ostream& operator<<(std::ostream& os, const Point& point);
};
#endif  // POINT_H