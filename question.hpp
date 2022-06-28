#pragma once

#include <string>
#include <fstream>
#include <iostream>

class Question {
public:
    Question() = default;

    void printQuestionAndAnswers();

    void loadQuestionAndAnswers(const std::string nameOfFile, const std::string ID);

    std::string correctFullAnswer() const;

    char getCorrectAnswer() const;

    void setCorrectAnswer(char newAnswer);

    std::string getQuestion() const;

    void setQuestion(std::string newQuestion);


    std::string firstAnswer;
    std::string secondAnswer;
    std::string thirdAnswer;
    std::string forthAnswer;
private:
    std::string ID_of_question;
    std::string question;

    std::string correctAnswer;
};