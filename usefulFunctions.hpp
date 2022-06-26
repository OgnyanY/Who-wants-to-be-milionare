#ifndef WHO_WANTS_TO_BE_MILIONARE_USEFULFUNCTIONS_HPP
#define WHO_WANTS_TO_BE_MILIONARE_USEFULFUNCTIONS_HPP

#include <string>

char levelFromIntToChar(int level);

void printNewLines(int number);

void printEmptySpaces(int number);

void firstTwoDigitsIDGenerator(int level, char questionID[6]);

void lastFiveDigitsIDGenerator(int topicChoice, int number, char fullQuestionID[]);

void FillingEmptySpace(std::string &option, int optionSize);

void printBorder();

char validInput(const std::string &str);

void
ValidInputForWords(const char enteringWord[], const char possibleWord[], int MessageSize, bool &incorrectValidation);

void AddAdditonalCharacters(char OGstring[], int &OGlength, char addstr1[]);

void ProperNewLineToString(char question[]);

void ThanksForPlaying();

void QuestionCheckNewLine(char question[]);

#endif //WHO_WANTS_TO_BE_MILIONARE_USEFULFUNCTIONS_HPP
