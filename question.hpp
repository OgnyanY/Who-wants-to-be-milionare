#pragma once
#include <string>

class Question {
 public:
  Question() = default;
  void printQuestionAndAnswers();
  void loadQuestionAndAnswers(const std::string nameOfFile, const std::string ID);

 private:
  std::string ID_of_question;
  std::string question;
  std::string firstAnswer;
  std::string secondAnswer;
  std::string thirdAnswer;
  std::string forthAnswer;
  std::string correctAnswer;
};