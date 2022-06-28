#pragma once

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
