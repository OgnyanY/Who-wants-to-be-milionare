//
// Created by Acer on 24.6.2022 г..
//

#ifndef WHO_WANTS_TO_BE_MILIONARE_NEWQUESTION_HPP
#define WHO_WANTS_TO_BE_MILIONARE_NEWQUESTION_HPP

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "usefulFunctions.hpp"
#include "newGame.hpp"
#include "id.hpp"
#include "question.hpp"

class newQuestion {
public:
    void EnteringNewQuestion();

private:
    void printSuccessfulNewQuestion();

    void enteringNewInfoIntoFile(const std::string &fileName, const std::string &question,
                                 const std::string &option1, const std::string &option2,
                                 const std::string &option3, const std::string &option4,
                                 char correctAnswer, int &numberOfQuestion, const std::string &fullID);

    void writingNewQuestionAnswers(Question &question, int &diffChoice, std::string fullQuestionID);

    int selectingDifficultyOfQuestion(std::vector<int> &numberOfQuestionChoices);
    void printSelectingDifficultyOfQuestion();

    char selectingCategory(const std::string &choiceSelection);
    void printSelectingCategory();

    std::string selectTopic(char &choice);
    void searchHowManyPossibleQuestions(const std::string &nameOfFile, int &timesQuestionExists,
                                        std::string questionID);

    void writeQuestionGuide(int diffChoice, Question &question);
    void writeAnswersGuide(std::string &option1, std::string &option2,
                           std::string &option3, std::string &option4);
    void printQuestionPreview(const std::string& question,
                              const std::string& option1, const std::string& option2,
                              const std::string& option3, const std::string& option4,
                              char correctAnswer, int &diffChoice, const std::string &fullQuestionID);
    void writeCorrectAnswerGuide(Question &question);

};


#endif //WHO_WANTS_TO_BE_MILIONARE_NEWQUESTION_HPP
