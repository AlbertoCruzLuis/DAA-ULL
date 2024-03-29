/*=======================================================================
|| @Author: Alberto Cruz Luis
|| @Email: alu0101217734@ull.edu.es
|| @Github: https://github.com/AlbertoCruzLuis
|| @Date: April 2021
|| @University: ULL in Tenerife
|| @Course: DAA
|| @Version: 06-LCS_DynamicProgramming
|| @Info: https://en.wikipedia.org/wiki/Dynamic_programming
=======================================================================*/

#include <iostream>
#include <map>
#include <vector>

class LongestCommonSequence {
 private:
  std::vector<std::map<int, std::string>> hash_table_;

 public:
  LongestCommonSequence(std::string sub_chain, std::string chain);
  ~LongestCommonSequence() {}

  void execute(std::string sub_chain, std::string chain, int rows, int cols);

  friend std::ostream& operator<<(std::ostream& os,
                                  const LongestCommonSequence& lcs);
};
