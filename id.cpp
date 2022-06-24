#include "id.hpp"

#include <fstream>
#include <iostream>

ID::ID(const std::string id) : id(id) {}

int ID::numberOfVariationsOfAQuestion(const std::string nameOfFile) {
  std::ifstream currentLine(nameOfFile);

  if (!currentLine.is_open()) {
    std::cout << "file is not open!";
    return 0;
  }

  std::string searchedIdFirstPart;
  std::string currentIdFirstPart = id.substr(0, 5);
  int variations = 0;

  while (std::getline(currentLine, searchedIdFirstPart, '\n')) {
    searchedIdFirstPart = searchedIdFirstPart.substr(0, 5);
    if (searchedIdFirstPart == currentIdFirstPart) {
      variations++;
    }
  }

  return variations;
}