#pragma once
#include <vector>
#include <time.h>

#include "id.hpp"
#include "question.hpp"

class NewGame {
 public:
  NewGame();
  int pickATopic();
  void startGame();
  int selectRandomTopic();
  void nameOfTopic();

 private:
  int level;
  bool availableFiftyFiftyJoker;
  bool availableAudienceHelpJoker;
  bool availableFriendCallJoker;

  bool randomTopic;
  int chosenTopic;

  bool gameLost;

  std::string nameOfFile;

  std::vector<int> possibleEarnings = {100,   200,    300,    500,    1000,
                                       2000,  4000,   8000,   16000,  32000,
                                       64000, 125000, 250000, 500000, 1000000};
};