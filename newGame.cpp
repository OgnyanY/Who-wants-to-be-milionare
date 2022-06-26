#include "newGame.hpp"

NewGame::NewGame()
    : level(1),
      availableFiftyFiftyJoker(true),
      availableAudienceHelpJoker(true),
      availableCallFriendJoker(true),
      randomTopic(false),
      chosenTopic(0),
      gameLost(false),
      possibleAnswers("ABCD") {}

int NewGame::pickATopic() {
    printPickATopic();

    std::string possibleChoices = { '1', '2', '3', '4', '5', '9', '0' };
    char choice = validInput(possibleChoices);

    if(choice == 0){//return to main menu
        return 0;
    }

    randomTopic = false;//adding option to choose all categories

    std::string topic = selectTopic(choice);

    ///StartNewGame(topic, randomTopic);

    return choice - '0';

}

void NewGame::startGame() {
  do {
    choosingNameOfFile();
    generateID();
    loadAndPrintQuestionAndAnswers();
    if (availableJokers()) {
      if (askToUseJoker()) {
        std::string jokersToUse;
        showAvailableJokers(jokersToUse);
        char decision = validInput(jokersToUse);
        useDesiredJoker(decision);
      }
    }

    validatingAnswer();
  } while (!gameLost && level < 15);
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

void NewGame::choosingNameOfFile() {
  if (randomTopic) {
    chosenTopic = selectRandomTopic();
  }
  nameOfTopic();
}

void NewGame::generateID() {
  id.firstTwoDigitsIDGenerator(level);
  int variantOfQuestion =
      rand() % id.numberOfVariationsOfAQuestion(nameOfFile) + 1;
  id.lastFiveDigitsIDGenerator(chosenTopic, variantOfQuestion);
}

void NewGame::loadAndPrintQuestionAndAnswers() {
  currentQuestion.loadQuestionAndAnswers(nameOfFile, id.getID());
  std::system("cls");
  currentQuestion.printQuestionAndAnswers();
  possibleAnswers = "ABCD";
}

bool NewGame::availableJokers() {
  return (availableFiftyFiftyJoker || availableAudienceHelpJoker ||
          availableCallFriendJoker);
}

bool NewGame::askToUseJoker() {
  std::cout
      << "  Do you want to use a joker? (type: 'y' for yes or 'n' for no)";
  return validInput("yn") == 'y';
}

void NewGame::showAvailableJokers(std::string jokersToUse) {
  std::string outputString;
  if (availableFiftyFiftyJoker) {
    outputString += "press X for 50/50\n";
    jokersToUse += "X";
  }
  if (availableAudienceHelpJoker) {
    outputString += "press Y for help from the audience";
    jokersToUse += "Y";
  }
  if (availableCallFriendJoker) {
    outputString += "press Z for calling a friend";
    jokersToUse += "Z";
  }
  outputString += "press 0 for escape:";
  jokersToUse += "0";

  std::cout << outputString;
}

void NewGame::useDesiredJoker(char decision) {
  if (decision == 'X') {
      fiftyFiftyJoker.useJoker(currentQuestion.getCorrectAnswer(), currentQuestion.firstAnswer,
                            currentQuestion.secondAnswer, currentQuestion.thirdAnswer,
                            currentQuestion.forthAnswer);

      system("cls");//clearing console
      currentQuestion.printQuestionAndAnswers();

      availableFiftyFiftyJoker = false;

  } else if (decision == 'Y') {
      callFriendJoker.useJoker("ABCD",currentQuestion.getCorrectAnswer(), level);

      system("cls");//clearing console
      currentQuestion.printQuestionAndAnswers();

      availableCallFriendJoker = false;

  } else if (decision == 'Z') {
      audienceHelpJoker.useJoker("ABCD",currentQuestion.getCorrectAnswer(), level);

      system("cls");//clearing console
      currentQuestion.printQuestionAndAnswers();

      availableAudienceHelpJoker = false;

  } else {
      system("cls");//clearing console
      currentQuestion.printQuestionAndAnswers();
  }
}

char NewGame::giveAnswer() {
  std::cout << "  Your answer (" << possibleAnswers[0] << ", "
            << possibleAnswers[1] << ", " << possibleAnswers[2] << " or "
            << possibleAnswers[3] << "): ";

  return validInput(possibleAnswers);
}

bool NewGame::checkIfAnswerIsCorrect(char answer) {
  return answer == currentQuestion.getCorrectAnswer();
}

void NewGame::printPassedQuestion() {  // printing won amount of money for round
  printNewLines(6);
  printBorder();
  std::cout << '\n';
  std::cout << "                                      Congratulations, you won "
            << possibleEarnings[level - 1] << '$' << '\n';
  printBorder();
}

void NewGame::printGameOver() {  // printing game over
  system("cls");
  printNewLines(6);
  printBorder();
  std::cout << '\n';  // if user lost game, he wins an amount, after a certain
                      // level is passed
  std::cout
      << "                                                      GAME OVER\n";
  std::cout
      << "                                          The correct answer was: "
      << currentQuestion.correctFullAnswer()
      << '\n';  // printing the correct answer
  if (level <= 5) {
    std::cout
        << "                                                 You have won 0$";
  } else if (level > 5 && level <= 10) {
    std::cout
        << "                                                You have won 1000$";
  } else if (level > 10 && level < 16) {
    std::cout
        << "                                               You have won 32000$";
  }
  printBorder();
}

bool NewGame::keepingMoneyQuestion() {
  system("cls");
  char yesNo = '\0';

  printPassedQuestion();
  std::cout << "\n                     Do you want to keep the money, and stop "
               "playing ?(type 'y' for yes or 'n' for no)";

  std::cin >> yesNo;

  while (yesNo != 'y' && yesNo != 'n') {
    system("cls");
    printPassedQuestion();
    std::cout
        << "\n                     Do you want to keep the money, and stop "
           "playing ?(type 'y' for yes or 'n' for no)";
    std::cout << "\n\n                                  Incorrect validation, "
                 "please type (y/n)";
    std::cin >> yesNo;
  }
  return yesNo == 'y';
}

void NewGame::keepMoneyMessage() {
  system("cls");
  printNewLines(6);
  std::cout << "  ========================================== Who wants to be a "
               "millionaire? ==========================================\n\n";
  std::cout << "                             You won "
            << possibleEarnings[level - 1]
            << "$ in Who wants to be a millionaire, thanks for playing! ";
  std::cout << '\n';
  printBorder();
}

void NewGame::validatingAnswer() {
  char answer = giveAnswer();
  std::system("cls");
  if (checkIfAnswerIsCorrect(answer)) {
    level++;
    if (keepingMoneyQuestion()) {
      gameLost = true;
      keepMoneyMessage();
    }
  } else {
    gameLost = true;
    printGameOver();
    std::system("pause");
    std::system("cls");
  }
}

void NewGame::printPickATopic() {
    printNewLines(6);
    std::cout << "  ========================================== Who wants to be a millionaire? ==========================================\n\n";
    std::cout << '\n';
    std::cout << "                                                   Choose category:\n\n";
    std::cout << "                                                        1. Life\n";
    std::cout << "                                                        2. History\n";
    std::cout << "                                                        3. Cinema\n";
    std::cout << "                                                        4. Sports\n";
    std::cout << "                                                        5. Politics\n\n";
    std::cout << "                                                        9. All categories\n\n";
    std::cout << "                                                 0. For returning to Main Menu\n\n";

    printBorder();
    std::cout << "Enter your choice: ";
}

std::string NewGame::selectTopic(char &choice) {
    if (choice == '1') {
        //std::string topic = "Life.txt";
        randomTopic = false;
        return "Life.txt";
    }
    else if (choice == '2') {
        //std::string topic = "History.txt";
        randomTopic = false;
        return "History.txt";
    }
    else if (choice == '3') {
        //std::string topic = "Cinema.txt";
        randomTopic = false;
        return "Cinema.txt";
    }
    else if (choice == '4') {
        //std::string topic = "Sports.txt";
        randomTopic = false;
        return "Sports.txt";
    }
    else if (choice == '5') {
        //std::string topic = "Politics.txt";
        randomTopic = false;
        return "Politics.txt";
    }
    else if (choice == '9') {
        randomTopic = true;
        //std::string topic = { '\0' };
        return "\0";
    }
    else {
        system("cls");//clearing console
        return "-1";
    }
}
