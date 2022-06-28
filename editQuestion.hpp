//
// Created by Acer on 26.6.2022 г..
//

#ifndef WHO_WANTS_TO_BE_MILIONARE_EDITQUESTION_HPP
#define WHO_WANTS_TO_BE_MILIONARE_EDITQUESTION_HPP

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include "usefulFunctions.hpp"
#include "newQuestion.hpp"

class EditQuestion {
public:
    void EditingExistingQuestion();
private:
    void AskForID(std::string &searchQuestionID, char exitSymbol, std::string &fileName);

    void SearchIDInFiles(std::string &searchQuestionID, const std::string& detZero,
                         std::string &fileName, bool &questionExists);

    void askForIDGuide(std::string &searchQuestionID);

    void pickFileName(std::string &fileName, int number);


};


#endif //WHO_WANTS_TO_BE_MILIONARE_EDITQUESTION_HPP
