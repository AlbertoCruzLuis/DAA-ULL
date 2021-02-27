#include "Label.hpp"

Label::Label(std::string name, int line_position)
    : name_(name), line_position_(line_position) {}

std::string Label::get_name() { return name_; }

int Label::get_line_position() { return line_position_; }