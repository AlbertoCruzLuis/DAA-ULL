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
