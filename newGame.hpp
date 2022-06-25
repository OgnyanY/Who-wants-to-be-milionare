#pragma once
#include <time.h>
#include <vector>
#include <cstdlib>

#include "id.hpp"
#include "question.hpp"


class NewGame {
 public:
  NewGame();
  int pickATopic();
  void startGame();

  int selectRandomTopic();
  void nameOfTopic();
  void choosingNameOfFile();//
  void generateID();//
  void loadAndPrintQuestionAndAnswers();//

  bool availableJokers();
  bool askToUseJoker();
  void showAvailableJokers(std::string jokersToUse);
  void useDesiredJoker(char decision);

  char giveAnswer();
  bool checkIfAnswerIsCorrect(char answer);
  void printPassedQuestion();
  void printGameOver();
  bool keepingMoneyQuestion();
  void keepMoneyMessage();
  void validatingAnswer();//

 public://private:
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

  ID id;
  Question currentQuestion;

  std::string possibleAnswers;
};