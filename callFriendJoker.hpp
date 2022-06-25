#ifndef WHO_WANTS_TO_BE_MILIONARE_CALLFRIENDJOKER_HPP
#define WHO_WANTS_TO_BE_MILIONARE_CALLFRIENDJOKER_HPP

#include <iostream>
#include "usefulFunctions.hpp"
#include <fstream>
#include <ctime>
#include <stdlib.h>
//#include "NewGame.h"

class CallFriendJoker {
public:
    void callFriend(std::string &possibleAnswers, char &correctAnswer, int &level);

private:
    int calculatePercentChanceOfLying(int &level);

    void giveAnswerToQuestion(int &randomNumber, int &percentChanceOfLying, std::string &possibleAnswers, char &correctAnswer);

    int getIndexOfCorrectAnswer(std::string &possibleAnswers, char &correctAnswer);

    void giveWrongAnswer(std::string &possibleAnswers, char &correctAnswer);

    void giveCorrectAnswer(char &correctAnswer);
};


#endif //WHO_WANTS_TO_BE_MILIONARE_CALLFRIENDJOKER_HPP
