#ifndef WHO_WANTS_TO_BE_MILIONARE_CALLFRIENDJOKER_HPP
#define WHO_WANTS_TO_BE_MILIONARE_CALLFRIENDJOKER_HPP

#include <iostream>
#include <fstream>
#include <ctime>
#include <stdlib.h>
#include <string>

#include "usefulFunctions.hpp"

class CallFriendJoker {
public:
    virtual void useJoker(std::string possibleAnswers, char correctAnswer, int level);

protected:
    virtual int getIndexOfCorrectAnswer(std::string &possibleAnswers, char &correctAnswer);

private:
    virtual int calculatePercentChanceOfLying(int &level);

    virtual void giveAnswerToQuestion(int &randomNumber, int &percentChanceOfLying,
                                      std::string &possibleAnswers, char &correctAnswer);

    virtual void giveWrongAnswer(std::string &possibleAnswers, char &correctAnswer);

    virtual void giveCorrectAnswer(char &correctAnswer);
};


#endif //WHO_WANTS_TO_BE_MILIONARE_CALLFRIENDJOKER_HPP
