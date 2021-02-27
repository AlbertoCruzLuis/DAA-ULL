#include "FileParser.hpp"
/**
 * @brief Construct a new FileParser::FileParser object
 *
 * @param inFileName
 * @param outFileName
 * @param commentTypes
 */
FileParser::FileParser(std::string inFileName) {
  file_.open(inFileName, std::fstream::in | std::fstream::out);

  analyzeFile();
}

std::vector<Label> FileParser::get_list_label() { return list_label_; }

std::vector<Instruction*> FileParser::get_list_instructions() {
  return list_instruction_;
}

void FileParser::analyzeFile() {
  std::string line;
  int line_counter = 0;
  while (getline(file_, line)) {
    // Check Comments & EmptyLine
    if (!isComments(line) && !isEmptyLine(line)) {
      formattedData_.push_back(line);
      std::string label;
      std::cout << line_counter << ": ";
      if ((label = findLabel(line)) != "") {
        // Add Label to List Labels
        list_label_.push_back(Label(label, line_counter));
        // std::cout << "Label -> " << label << "\t";
      }

      std::pair<std::string, std::string> instruction = findInstruction(line);
      std::cout << "Instruction: " << instruction.first << " "
                << instruction.second << "\n";

      // Validate Instructions & Set Instructions
      list_instruction_.push_back(
          validateOperation(instruction.first, instruction.second));

      /*for (auto&& instruction : list_instruction_) {
        instruction->execute();
        std::cout << instruction << std::endl;
      }*/
    }

    line_counter++;
  }
  // file_.close();
}

bool FileParser::isComments(std::string line) {
  // Implementation of diogonals "//"
  /*if (line.length() < 2) return false;
  if (line[0] == '/' && line[1] == '/') {
    return true;
  }*/
  // Implementation of hasthags "#"
  if (line.length() < 1) return false;
  if (line[0] == '#') {
    return true;
  }
}

Instruction* FileParser::validateOperation(std::string name,
                                           std::string value) {
  if (name == "READ" || name == "read") {
    return new Read(name, value);
  } else if (name == "LOAD" || name == "load") {
    return new Load(name, value);
  } else if (name == "JUMP" || name == "jump") {
    return new Jump(name, value);
  } else if (name == "JZERO" || name == "jzero") {
    return new Jzero(name, value);
  } else if (name == "WRITE" || name == "write") {
    return new Write(name, value);
  } else if (name == "HALT" || name == "halt") {
    return new Halt(name, value);
  }

  throw "Instruction Error";
}

bool FileParser::isEmptyLine(std::string line) {
  return (line.length() == 0) ? true : false;
}

std::string FileParser::findLabel(std::string line) {
  std::istringstream iss(line);
  std::string label;
  iss >> label;
  if (label.back() == ':') {
    label.pop_back();
    return label;
  }
  return "";
}

std::pair<std::string, std::string> FileParser::findInstruction(
    std::string line) {
  std::istringstream iss(line);
  std::string data;
  std::string instructionName;
  std::string instructionValue;

  iss >> data;
  // Check if not exist label
  if (findLabel(data) == "") {
    instructionName = data;
  } else {
    iss >> instructionName;
  }

  iss >> instructionValue;

  return std::make_pair(instructionName, instructionValue);
}