#include "Experiment.hpp"

#include "Timer/timer.cpp"

Experiment::Experiment(Graph& graph, std::string type_algorithm,
                       std::string neighbour_algorithm, int max_iterations,
                       int rcl_size, int value_environmental_structure)
    : type_algorithm_(type_algorithm),
      neighbour_algorithm_(neighbour_algorithm),
      max_iterations_(max_iterations),
      rcl_size_(rcl_size),
      value_environmental_structure_(value_environmental_structure) {
  /*int i = 0;
  for (auto&& row : graph.get_values_of_arcs()) {
    std::cout << i << ": ";
    for (auto&& value : row) {
      std::cout << value.get_value_of_arc() << " ";
    }
    i++;
    std::cout << "\n";
  }*/

  Algorithm* algorithm = choose_algorithm(type_algorithm, neighbour_algorithm);
  timer([algorithm, &graph]() {
    TaskScheduler taskScheduler(algorithm);
    std::cout << taskScheduler.run(graph) << "\n";
  });
}

Algorithm* Experiment::choose_algorithm(std::string type_algorithm,
                                        std::string neighbour_algorithm) {
  if (type_algorithm == "greedy") {
    return new Greedy();
  }
  if (type_algorithm == "grasp") {
    return new GRASP(choose_neighbour_algorithm(neighbour_algorithm),
                     max_iterations_, rcl_size_);
  }
  if (type_algorithm == "multiboot") {
    return new MultiBoot(choose_neighbour_algorithm(neighbour_algorithm),
                         max_iterations_);
  }
  if (type_algorithm == "gvns") {
    return new GVNS(value_environmental_structure_, max_iterations_);
  }

  return new Greedy();
}

NeighbourAlgorithm* Experiment::choose_neighbour_algorithm(
    std::string type_algorithm) {
  if (type_algorithm == "ExchangeOwnMachine") {
    return new ExchangeOwnMachine();
  }
  if (type_algorithm == "ExchangeExternalMachine") {
    return new ExchangeExternalMachine();
  }
  if (type_algorithm == "ReinsertionOwnMachine") {
    return new ReinsertionOwnMachine();
  }
  if (type_algorithm == "ReinsertionExternalMachine") {
    return new ReinsertionExternalMachine();
  }
  return new ExchangeExternalMachine();
}
