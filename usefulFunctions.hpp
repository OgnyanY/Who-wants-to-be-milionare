#pragma once

#include <string>
#include <vector>

char levelFromIntToChar(int level);

void printNewLines(int number);

void printEmptySpaces(int number);

void fillingWithEmptySpace(std::string &option, int optionSize);

void printBorder();

char validInput(const std::string &str);

int validInput(const std::vector<int> &arr);

void thanksForPlaying();

std::string questionCheckForNewLine(std::string question);
