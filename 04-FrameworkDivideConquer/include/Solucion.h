/*=======================================================================
|| @Author: Alberto Cruz Luis
|| @Email: alu0101217734@ull.edu.es
|| @Github: https://github.com/AlbertoCruzLuis
|| @Date: March 2021
|| @University: ULL in Tenerife
|| @Course: DAA
|| @Version: 04-FrameworkDivideConquer
|| @Info: https://es.wikipedia.org/wiki/Algoritmo_divide_y_vencer%C3%A1s
=======================================================================*/

#ifndef SOLUCION_H_
#define SOLUCION_H_

#include <iostream>
#include <utility>
#include <vector>

class Solucion {
 public:
  Solucion() {}
  virtual ~Solucion() {}

  virtual void resolver() = 0;
  virtual void mezcla(std::pair<Solucion*, Solucion*> subSolutions) {}
  virtual Solucion* getInstance() {}
  std::vector<int> get_array() { return array_; }
  void set_array(std::vector<int> array) { array_ = array; }
  friend std::ostream& operator<<(std::ostream& os, const Solucion* solution) {
    std::cout << "SizeArray: " << solution->array_.size() << std::endl;
    for (auto&& element : solution->array_) {
      os << element << " - ";
    }
    os << "\n";
  }

 protected:
  std::vector<int> array_;
};

#endif /* SOLUCION_H_ */
