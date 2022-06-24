#include "question.hpp"

#include <fstream>
#include <iostream>

void Question::printQuestionAndAnswers() {
  std::cout << ID_of_question << '\n'
            << question << '\n'
            << firstAnswer << '\n'
            << secondAnswer << '\n'
            << thirdAnswer << '\n'
            << forthAnswer << '\n';
  std::cout << '\n' << correctAnswer;
}

void Question::loadQuestionAndAnswers(const std::string nameOfFile,
                                      const std::string ID) {
  std::ifstream currentLine(nameOfFile);

  if (!currentLine.is_open()) {
    std::cout << "file is not open!";
    return;
  }

  while (std::getline(currentLine, ID_of_question, '\n')) {
    if (this->ID_of_question == ID) {
      break;
    }
  }
  std::getline(currentLine, question, '\n');
  std::getline(currentLine, firstAnswer, '\n');
  std::getline(currentLine, secondAnswer, '\n');
  std::getline(currentLine, thirdAnswer, '\n');
  std::getline(currentLine, forthAnswer, '\n');

  currentLine.ignore();
  std::getline(currentLine, correctAnswer, '\n');

  currentLine.close();
}