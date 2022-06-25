#include "newGame.hpp"

NewGame::NewGame()
    : level(1),
      availableFiftyFiftyJoker(true),
      availableAudienceHelpJoker(true),
      availableFriendCallJoker(true),
      randomTopic(false),
      chosenTopic(0),
      gameLost(false) {}

// int NewGame::pickATopic() {}  // TODO

void NewGame::startGame() {
  do {
    if (randomTopic) {
      chosenTopic = selectRandomTopic();
    }
    nameOfTopic();

    id.firstTwoDigitsIDGenerator(level);
    int variantOfQuestion =
        rand() % id.numberOfVariationsOfAQuestion(nameOfFile) + 1;
    id.lastFiveDigitsIDGenerator(chosenTopic, variantOfQuestion);

    currentQuestion.loadQuestionAndAnswers(nameOfFile, id.getID());
    currentQuestion.printQuestionAndAnswers();
    // if(availableJokers()) SHOW MESSAGE FOR USING JOKERS

    char answer = giveAnswer();

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

bool NewGame::availableJokers() {
  // if(at least one joker is available){return true}
  return true;
}

char NewGame::giveAnswer() {
  std::cout << "  Your answer (" << possibleAnswers[0] << ", "
            << possibleAnswers[1] << ", " << possibleAnswers[2] << " or "
            << possibleAnswers[3] << "): ";

  return validInput(possibleAnswers);
}

 bool NewGame::checkIfAnswerIsCorrect(char answer){ // TODO
  return true;
 }