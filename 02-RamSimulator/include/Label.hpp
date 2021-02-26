#ifndef LABEL_H
#define LABEL_H

#include <iostream>
#include <vector>

class Label {
 private:
  std::string name_;
  int line_position_;

 public:
  Label(std::string name, int line_position);
  ~Label() {}
};

#endif  // LABEL_H