#include <algorithm>

#include "NeighbourAlgorithms/NeighbourAlgorithm.hpp"

class ExchangeExternalPoint : public NeighbourAlgorithm {
 public:
  std::vector<Solution> generateNeighbour(Solution& solution) {
    std::vector<Solution> neighbours;
    Solution current_solution = solution;
    for (size_t i = 0; i < current_solution.get_list_points().size(); i++) {
      for (size_t j = i + 1; j < current_solution.get_list_points().size();
           j++) {
        std::swap(current_solution.get_list_points()[i],
                  current_solution.get_list_points()[j]);
        neighbours.push_back(current_solution);
      }
    }
    return neighbours;
  }
};