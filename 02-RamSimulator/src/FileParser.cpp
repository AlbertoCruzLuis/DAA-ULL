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
      // std::cout << line_counter << ": ";
      if ((label = findLabel(line)) != "") {
        // Add Label to List Labels
        list_label_.push_back(Label(label, line_counter));
        /*std::cout << "LabelParse ->" << line_counter << ": " << label
                  << std::endl;*/
      }

      Instruction instruction = findInstruction(line);

      // Validate Instructions & Set Instructions
      list_instruction_.push_back(validateOperation(instruction));
      line_counter++;
    }
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

Instruction* FileParser::validateOperation(Instruction instruction) {
  std::string name = instruction.get_name();
  std::string value = instruction.get_value();
  char mode = instruction.get_mode();
  if (name == "READ" || name == "read") {
    return new Read(name, mode, value);
  } else if (name == "LOAD" || name == "load") {
    return new Load(name, mode, value);
  } else if (name == "JUMP" || name == "jump") {
    return new Jump(name, mode, value);
  } else if (name == "JZERO" || name == "jzero") {
    return new Jzero(name, mode, value);
  } else if (name == "WRITE" || name == "write") {
    return new Write(name, mode, value);
  } else if (name == "HALT" || name == "halt") {
    return new Halt(name);
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

Instruction FileParser::findInstruction(std::string line) {
  std::istringstream iss(line);
  std::string data;
  std::string instructionName;
  char instructionMode;
  std::string instructionValue;

  iss >> data;
  // Check if not exist label
  if (findLabel(data) == "") {
    instructionName = data;
  } else {
    iss >> instructionName;
  }

  iss >> instructionValue;
  if (instructionValue.front() == '=' || instructionValue.front() == '*') {
    instructionMode = instructionValue.front();
    instructionValue.erase(instructionValue.begin());
  }

  return Instruction(instructionName, instructionMode, instructionValue);
}