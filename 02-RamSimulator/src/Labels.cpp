#include "Labels.hpp"

void Labels::push(std::string name, int line_position) {
  list_labels_.insert({name, line_position});
}

int Labels::operator[](std::string name) { return list_labels_[name]; }