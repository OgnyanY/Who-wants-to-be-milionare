#pragma once

#include <stdlib.h>

#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "question.hpp"
#include "usefulFunctions.hpp"

class FiftyFiftyJoker {
public:
    void useJoker(Question &question);

private:
    int findCorrectAnswerIndex(Question &question);

    int findFirstOptionToDelete(int &skipOption);

    int findSecondOptionToDelete(int &skipOption, int &firstDeleteOptionIndex);

    void eraseWrongAnswer(int indexToDelete, Question &question);
};
