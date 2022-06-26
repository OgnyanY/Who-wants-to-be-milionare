#pragma once
#include <time.h>
#include <vector>
#include <cstdlib>

#include "id.hpp"
#include "question.hpp"
#include "fiftyFiftyJoker.hpp"
#include "callFriendJoker.hpp"
#include "audienceHelpJoker.hpp"


class NewGame {
 public:
  NewGame();
  void pickATopic();
  void startGame();

  int selectRandomTopic();
  void nameOfTopic();
  void choosingNameOfFile();//
  void generateID();//
  void loadAndPrintQuestionAndAnswers();//

  bool availableJokers();
  bool askToUseJoker();
  void showAvailableJokers(std::string& jokersToUse);
  void useDesiredJoker(char decision);

  char giveAnswer();
  bool checkIfAnswerIsCorrect(char answer);
  void printPassedQuestion();
  void printGameOver();
  bool keepingMoneyQuestion();
  void keepMoneyMessage();
  void validatingAnswer();

  void printPickATopic();

 public://private:
  int level;
  bool availableFiftyFiftyJoker;
  bool availableAudienceHelpJoker;
  bool availableCallFriendJoker;

  bool randomTopic;
  int chosenTopic;

  bool gameLost;

  std::string nameOfFile;

  std::vector<int> possibleEarnings = {100,   200,    300,    500,    1000,
                                       2000,  4000,   8000,   16000,  32000,
                                       64000, 125000, 250000, 500000, 1000000};

  ID id;
  Question currentQuestion;

  std::string possibleAnswers;

  CallFriendJoker callFriendJoker;
  AudienceHelpJoker audienceHelpJoker;
  FiftyFiftyJoker fiftyFiftyJoker;
};