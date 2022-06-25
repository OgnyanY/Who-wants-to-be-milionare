#include "usefulFunctions.hpp"

#include <iomanip>
#include <iostream>
#include <string>


using namespace std;

char levelFromIntToChar(
    int level) {  // turning level number into number of ID    example: ID:01
  return '0' + level;
}
void printNewLines(int number) {
  for (int i = 0; i < number; i++) {
    cout << '\n';
  }
}
void printEmptySpaces(int number) {
  for (int i = 0; i < number; i++) {
    cout << ' ';
  }
}

void printBorder() {
  cout << endl;
  cout << setw(3);
  const int SIZE_OF_CONSOLE_ROW = 120;
  for (int i = 0; i < (SIZE_OF_CONSOLE_ROW - 4); i++) {  // printing border
    cout << '=';
  }
  cout << endl;
}

char validInput(const std::string& str) {
  bool validChoice = false;
  char number;
  do {
    cin >> number;
    for (int i = 0; i < str.size(); i++) {  // if the input does not match with
                                            // any of the remaining options,
      if (number !=
          str[i]) {  // continue the loop until a viable option is inputted
        continue;
      }
      validChoice = true;  // flag for stopping the function
      break;
    }
  } while (!validChoice);  // looping while a valid choice isn't entered
  return number;
}

void ValidInputForWords(const char enteringWord[], const char possibleWord[],
                        int MessageSize, bool& incorrectValidation) {
  for (int i = 0; i < MessageSize; i++) {
    if (enteringWord[i] != possibleWord[i]) {
      incorrectValidation =
          true;  // if an element is different, break the loop and change bool
                 // to show that the words do not match
      break;
    }
  }
}

void AddAdditonalCharacters(char OGstring[], int& OGlength, char addstr1[]) {
  int additionalLength1 = StrLength(addstr1);
  for (int i = OGlength - 1; i >= 0;
       i--) {  // coppying all elemtnts 'i' positions forward, so new characters
               // can be swapped in the begining
    OGstring[i + additionalLength1] = OGstring[i];
  }

  for (int i = 0; addstr1[i] != '\0';
       i++) {  // coppying the text, while the loop meets a terminating zero
    OGstring[i] = addstr1[i];
  }
  OGlength = StrLength(OGstring);
}
void FillingEmptySpace(std::string option, int optionSize) {  // filling the space of an option for 50/50 joker
  for (int i = 0; i < optionSize; i++) {
    option[i] = ' ';
  }
  option[optionSize] = '\0';
}
void ProperNewLineToString(char question[]) {
  const int SIZE_OF_CONSOLE_ROW =
      120;  // this will be the default size of the row of the console
  int questionSize = StrLength(question);  // finding the size of the question

  // if the size is more than 116(which is where the double lines end), this
  // part of the code finds where is the last position, where there isn't a
  // latin letter, and starts copying the rest of the elements from his right
  // side 2 steps over, then rewrites the found position to a new line, and the
  // second two elements after him to 2 space bars
  if (questionSize > (SIZE_OF_CONSOLE_ROW - 4)) {
    int startElementToCopy = SIZE_OF_CONSOLE_ROW - 4;
    for (startElementToCopy = SIZE_OF_CONSOLE_ROW - 4;
         ((question[startElementToCopy] <= 'Z' &&
           question[startElementToCopy] >= 'A') ||
          (question[startElementToCopy] <= 'z' &&
           question[startElementToCopy] >= 'a'));
         startElementToCopy--) {
    }
    for (int currentPosOfElement = questionSize;
         currentPosOfElement > startElementToCopy; currentPosOfElement--) {
      question[currentPosOfElement + 2] = question[currentPosOfElement];
    }
    question[startElementToCopy] = '\n';
    question[startElementToCopy + 1] = ' ';
    question[startElementToCopy + 2] = ' ';
  }
}
void ThanksForPlaying() {  // exiting message
  printNewLines(6);
    printBorder();
  cout << "\n\n                                         Thanks for playing, "
          "have a nice day !\n\n";
    printBorder();
  printNewLines(6);
}

void QuestionCheckNewLine(
    char question[]) {  // checking if in the inserted new question somewhere is
                        // a symbol for new line, if yes turns it into empty
                        // space
  int sizeQuestion = StrLength(question);
  for (int i = 0; i < sizeQuestion; i++) {
    if (question[i] == '\n') {
      question[i] = ' ';
    }
  }
}