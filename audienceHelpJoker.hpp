#ifndef WHO_WANTS_TO_BE_MILIONARE_AUDIENCEHELPJOKER_HPP
#define WHO_WANTS_TO_BE_MILIONARE_AUDIENCEHELPJOKER_HPP

#include <stdlib.h>

#include <ctime>
#include <fstream>
#include <iostream>
#include <string>

#include "callFriendJoker.hpp"
#include "usefulFunctions.hpp"

class AudienceHelpJoker : public CallFriendJoker {
 private:
  void giveWrongAnswer(std::string &possibleAnswers,
                       char &correctAnswer) override;

  void giveCorrectAnswer(char &correctAnswer) override;
};

#endif  // WHO_WANTS_TO_BE_MILIONARE_AUDIENCEHELPJOKER_HPP
