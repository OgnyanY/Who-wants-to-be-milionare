#pragma once

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include "usefulFunctions.hpp"
#include "newQuestion.hpp"

class EditQuestion {
public:
    void editQuestion();

private:
    void writeIdToSearchMessage();

    std::string inputIdToSearch();

    bool askToEditGivenQuestion();

    void enterNewInformation();

    std::vector<std::string> loadOldInformationIntoVector();

    void writeNewInformationIntoFile(std::vector<std::string> newInformation);

    void printSuccessfullyEditedQuestionMessage();

    ID id;
    Question question;
};
