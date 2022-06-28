#pragma once

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "usefulFunctions.hpp"
#include "newGame.hpp"
#include "id.hpp"
#include "question.hpp"

class NewQuestion {
public:
    void EnteringNewQuestion();

private:
    void printSuccessfulNewQuestion();

    void enteringNewInfoIntoFile(const std::string &fileName, const Question &question,
                                 int &numberOfQuestion, const std::string &fullID);

    void writingNewQuestionAnswers(Question &question, int &diffChoice, std::string fullQuestionID);

    int selectingDifficultyOfQuestion(std::vector<int> &numberOfQuestionChoices);

    void printSelectingDifficultyOfQuestion();

    char selectingCategory(const std::string &choiceSelection);

    void printSelectingCategory();

    std::string selectTopic(char &choice);

    void generateID(ID &questionID, int diffChoice, const std::string &topic, char categoryChoice);

    void generateQuestion(Question &question, ID &questionID, int diffChoice, const std::string &topic);

    void writeQuestionGuide(int diffChoice, Question &question);

    void writeAnswersGuide(Question &question);

    void printQuestionPreview(const Question &question, int &diffChoice, const std::string &fullQuestionID);

    void writeCorrectAnswerGuide(Question &question);

    std::string choiceSelection = {'1', '2', '3', '4', '5', '0'};
    std::vector<int> numberOfQuestionChoices = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
};
