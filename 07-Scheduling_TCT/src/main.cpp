/*=======================================================================
|| @Author: Alberto Cruz Luis
|| @Email: alu0101217734@ull.edu.es
|| @Github: https://github.com/AlbertoCruzLuis
|| @Date: April 2021
|| @University: ULL in Tenerife
|| @Course: DAA
|| @Version: 07-Scheduling_TCT
|| @Info: https://en.wikipedia.org/wiki/Parallel_task_scheduling_problem
=======================================================================*/

#include <iostream>

#include "CommandLineArguments.hpp"
#include "GRASP.hpp"
#include "Graph.hpp"
#include "Greedy.hpp"
#include "TaskScheduler.hpp"

int main(int argc, char* argv[]) {
  try {
    CommandLineArguments cmd_line(argc, argv);

    std::string file_name = cmd_line.get_list_arguments()[1];
    Graph graph(file_name);
    graph.calculate_values_of_arcs();

    int i = 0;
    for (auto&& row : graph.get_values_of_arcs()) {
      std::cout << i << ": ";
      for (auto&& value : row) {
        // std::cout << "T[" << value.first << "]: " << value.second << " ";
        std::cout << value.second << " ";
      }
      i++;
      std::cout << "\n";
    }

    TaskScheduler taskScheduler(new Greedy());
    taskScheduler.run(graph);

  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  } catch (const char* e) {
    std::cerr << e << '\n';
  } catch (...) {
  }

  return 0;
}