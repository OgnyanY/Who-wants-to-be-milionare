#ifndef WHO_WANTS_TO_BE_MILIONARE_FIFTYFIFTYJOKER_HPP
#define WHO_WANTS_TO_BE_MILIONARE_FIFTYFIFTYJOKER_HPP

#include <iostream>
#include <fstream>
#include <ctime>
#include <stdlib.h>
#include <string>
#include <vector>

#include "usefulFunctions.hpp"
#include "newGame.hpp"

class FiftyFiftyJoker {
public:
    void fiftyFifty(char correctAnswer, std::string &option1, std::string &option2,
                    std::string &option3, std::string &option4);

private:
    int findCorrectAnswerIndex(char correctAnswer, std::string &option1, std::string &option2,
                               std::string &option3, std::string &option4);

    int findFirstOptionToDelete(int &skipOption);

    int findSecondOptionToDelete(int &skipOption, int &firstDeleteOptionIndex);

    void eraseTwoWrongAnswers(int &firstDeleteOptionIndex, int &secondDeleteOptionIndex,
                              std::vector<std::string> &options);

    void takeNewOptions(std::string &option1, std::string &option2,
                        std::string &option3, std::string &option4, std::vector<std::string> &options);
};


#endif //WHO_WANTS_TO_BE_MILIONARE_FIFTYFIFTYJOKER_HPP
