#include "id.hpp"

#include <fstream>
#include <iostream>

#include "usefulFunctions.hpp"

ID::ID() : id("ID:XX-XXXXX") {}

ID::ID(const std::string id) : id(id) {}

std::string ID::getID() { return id; }

void ID::setID(std::string newId) { id = newId; }

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

// creating the ID that the program will
// look for only for front numbers
void ID::firstTwoDigitsIDGenerator(int level) {
  if (level < 10) {
    id[3] = '0';  // manual adding 0
    id[4] = levelFromIntToChar(level);
  } else {
    level = level % 10;
    id[3] = '1';  // manual adding 1
    id[4] = levelFromIntToChar(level);
  }
}

// creating the ID that the program will look for
// only for back numbers
void ID::lastFiveDigitsIDGenerator(const int topicChoice,
                                   int numberOfVariations) {
  id[6] = '0';
  id[7] = levelFromIntToChar(topicChoice);
  if (numberOfVariations >= 100) {
    int hundreds = numberOfVariations / 100;
    numberOfVariations = numberOfVariations % 100;
    int tens = numberOfVariations / 10;
    int ones = numberOfVariations % 10;

    id[8] = levelFromIntToChar(hundreds);
    id[9] = levelFromIntToChar(tens);
    id[10] = levelFromIntToChar(ones);
  } else if (numberOfVariations <= 99 && numberOfVariations >= 10) {
    int tens = numberOfVariations / 10;
    int ones = numberOfVariations % 10;

    id[8] = '0';
    id[9] = levelFromIntToChar(tens);
    id[10] = levelFromIntToChar(ones);
  } else {
    id[8] = '0';
    id[9] = '0';
    id[10] = levelFromIntToChar(numberOfVariations);
  }
}