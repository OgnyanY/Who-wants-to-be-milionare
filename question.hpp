#pragma once
#include <string>
#include <fstream>
#include <iostream>

class Question {
 public:
  Question() = default;
  void printQuestionAndAnswers();
  void loadQuestionAndAnswers(const std::string nameOfFile, const std::string ID);
  char getCorrectAnswer() const;
  std::string correctFullAnswer() const;

    std::string firstAnswer;
    std::string secondAnswer;
    std::string thirdAnswer;
    std::string forthAnswer;
 private:
  std::string ID_of_question;
  std::string question;

  std::string correctAnswer;
};