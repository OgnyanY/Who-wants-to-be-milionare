#include "fiftyFiftyJoker.hpp"

void FiftyFiftyJoker::useJoker(Question &question) {
  // setting the seed, from which the randomizer will randomize
  srand(time(nullptr));
  int skipOption = findCorrectAnswerIndex(question);

  int firstDeleteOptionIndex = findFirstOptionToDelete(skipOption);
  int secondDeleteOptionIndex =
      findSecondOptionToDelete(skipOption, firstDeleteOptionIndex);

  eraseWrongAnswer(firstDeleteOptionIndex, question);
  eraseWrongAnswer(secondDeleteOptionIndex, question);
}

int FiftyFiftyJoker::findCorrectAnswerIndex(Question &question) {
  if (question.firstAnswer[0] == question.getCorrectAnswer()) {
    return 1;
  } else if (question.secondAnswer[0] == question.getCorrectAnswer()) {
    return 2;
  } else if (question.thirdAnswer[0] == question.getCorrectAnswer()) {
    return 3;
  } else if (question.forthAnswer[0] == question.getCorrectAnswer()) {
    return 4;
  } else {
    return -1;
  }
}

int FiftyFiftyJoker::findFirstOptionToDelete(int &skipOption) {
  int firstDeleteOptionIndex;
  do {
    firstDeleteOptionIndex = rand() % 4 + 1;
  } while (firstDeleteOptionIndex == skipOption);
  return firstDeleteOptionIndex;
}

int FiftyFiftyJoker::findSecondOptionToDelete(int &skipOption,
                                              int &firstDeleteOptionIndex) {
  int secondDeleteOptionIndex;
  do {
    secondDeleteOptionIndex = rand() % 4 + 1;
  } while (secondDeleteOptionIndex == firstDeleteOptionIndex ||
           secondDeleteOptionIndex == skipOption);
  return secondDeleteOptionIndex;
}

void FiftyFiftyJoker::eraseWrongAnswer(int indexToDelete, Question &question) {
  switch (indexToDelete) {
    case 1:
      FillingEmptySpace(question.firstAnswer, question.firstAnswer.size());
      break;
    case 2:
      FillingEmptySpace(question.secondAnswer, question.secondAnswer.size());
      break;
    case 3:
      FillingEmptySpace(question.thirdAnswer, question.thirdAnswer.size());
      break;
    case 4:
      FillingEmptySpace(question.forthAnswer, question.forthAnswer.size());
      break;
    default:
      break;
  }
}