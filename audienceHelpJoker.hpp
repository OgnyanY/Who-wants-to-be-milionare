#ifndef WHO_WANTS_TO_BE_MILIONARE_AUDIENCEHELPJOKER_HPP
#define WHO_WANTS_TO_BE_MILIONARE_AUDIENCEHELPJOKER_HPP

#include <iostream>
#include <fstream>
#include <ctime>
#include <stdlib.h>
#include <string>

#include "usefulFunctions.hpp"
#include "callFriendJoker.hpp"

class AudienceHelpJoker :public CallFriendJoker {
private:
    void giveWrongAnswer(std::string &possibleAnswers, char &correctAnswer) override;

    void giveCorrectAnswer(char &correctAnswer) override;
};


#endif //WHO_WANTS_TO_BE_MILIONARE_AUDIENCEHELPJOKER_HPP
