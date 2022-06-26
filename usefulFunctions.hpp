#ifndef WHO_WANTS_TO_BE_MILIONARE_USEFULFUNCTIONS_HPP
#define WHO_WANTS_TO_BE_MILIONARE_USEFULFUNCTIONS_HPP

#include <string>
#include <vector>

char levelFromIntToChar(int level);

void printNewLines(int number);

void printEmptySpaces(int number);

void FillingEmptySpace(std::string &option, int optionSize);

void printBorder();

char validInput(const std::string &str);

int validInput(const std::vector<int>& arr);

void ValidInputForWords(const char enteringWord[], const char possibleWord[], int MessageSize, bool &incorrectValidation);

void AddAdditonalCharacters(char OGstring[], int &OGlength, char addstr1[]);

void ProperNewLineToString(char question[]);

void ThanksForPlaying();

std::string questionCheckNewLine(std::string question);

#endif //WHO_WANTS_TO_BE_MILIONARE_USEFULFUNCTIONS_HPP
