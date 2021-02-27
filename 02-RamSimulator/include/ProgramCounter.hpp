#ifndef PROGRAMCOUNTER_H
#define PROGRAMCOUNTER_H

class ProgramCounter {
 private:
  int current_address_;

 public:
  ProgramCounter();
  ~ProgramCounter() {}

  int get_current_address();
  void set_address(int address);
  void next_adress();
};

#endif  // PROGRAMCOUNTER_H