/*=======================================================================
|| @Author: Alberto Cruz Luis
|| @Email: alu0101217734@ull.edu.es
|| @Github: https://github.com/AlbertoCruzLuis
|| @Date: February / March 2021
|| @University: ULL in Tenerife
|| @Course: DAA
|| @Version: 02-RamSimulator
|| @Info: https://www.emustudio.net/documentation/user/ram/ram-cpu
=======================================================================*/

#ifndef READ_H
#define READ_H

#include "InTape.hpp"
#include "Instruction.hpp"
#include "Label.hpp"
#include "Memory.hpp"
#include "OutTape.hpp"
#include "ProgramCounter.hpp"

class Read : public Instruction {
 private:
  /* data */
 public:
  Read() {}
  Read(std::string name, char mode, std::string value)
      : Instruction(name, mode, value) {}
  ~Read() {}

  bool execute(Memory& memory, ProgramCounter& programCounter, InTape& inTape,
               OutTape& outTape, std::vector<Label> listLabel) {
    // std::cout << "Execute READ" << std::endl;
    if ((addressing_mode_.get_mode() == INMEDIATE) ||
        (addressing_mode_.get_mode() == INDIRECT)) {
      // Check!
      throw "Error Addressing Mode. Addressing Mode not Allowed";
    }
    // Indirect mode working only when the register what pointed is valid
    if (addressing_mode_.get_mode() == DIRECT) {
      int valueToInsert = inTape.read();
      // std::cout << "VAlueToInsert ->" << valueToInsert << std::endl;
      int id_register = stoi(value_);
      memory.read();
      memory.write(valueToInsert, id_register);
    }
    programCounter.next_address();
  }
};

#endif  // READ_H