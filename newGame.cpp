#include "newGame.hpp"

NewGame::NewGame()
    : level(1),
      availableFiftyFiftyJoker(true),
      availableAudienceHelpJoker(true),
      availableFriendCallJoker(true),
      randomTopic(false),
      chosenTopic(0),
      gameLost(false) {}

int NewGame::pickATopic() {}  // TODO

void NewGame::startGame() {
  do {
    if (randomTopic) {
      chosenTopic = selectRandomTopic();
    }
    nameOfTopic();

    id.firstTwoDigitsIDGenerator(level);
    int variantsOfQuestion = id.numberOfVariationsOfAQuestion(nameOfFile);
    id.lastFiveDigitsIDGenerator(chosenTopic, variantsOfQuestion);

    currentQuestion.loadQuestionAndAnswers(nameOfFile, id.getID());
    currentQuestion.printQuestionAndAnswers();

  } while (!gameLost);
}

int NewGame::selectRandomTopic() {
  srand(time(nullptr));
  return rand() % 5 + 1;
}

void NewGame::nameOfTopic() {
  if (chosenTopic == 1) {
    nameOfFile = "topics/Life.txt";
  } else if (chosenTopic == 2) {
    nameOfFile = "topics/History.txt";
  } else if (chosenTopic == 3) {
    nameOfFile = "topics/Cinema.txt";
  } else if (chosenTopic == 4) {
    nameOfFile = "topics/Sports.txt";
  } else {
    nameOfFile = "topics/Politics.txt";
  }
}