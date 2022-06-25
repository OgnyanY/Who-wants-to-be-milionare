//
// Created by Acer on 22.6.2022 г..
//

#include "mainMenuPage.hpp"

void MainMenuPage::createMainMenuPage() {
    do {
        printMainMenuPage();

        std::string possibleChoices = { '1', '2', '3', '0' };
        this->choice = validInput(possibleChoices);
        system("cls");//clearing console
        makeChoiceInMenu(this->choice);
    } while (choice != '0');
}

void MainMenuPage::printMainMenuPage() {
    printNewLines(6);
    std::cout << "  ========================================== Who wants to be a millionaire? ==========================================\n\n";
    std::cout << "                                                      1. New Game\n";
    std::cout << "                                                2. Entering new question\n";
    std::cout << "                                              3. Editing existing question\n";
    std::cout << "                                                         0.Exit\n";
    printBorder();

    std::cout << "\n                                                   Enter your choice: ";
}

void MainMenuPage::makeChoiceInMenu(char menuChoice) {

    if (menuChoice == '1') {
        //NewGame();
    }
    else if (menuChoice == '2') {
        //EnteringNewQuestion();
    }
    else if (menuChoice == '3') {
        //EditingExistingQuestion();
    }
    else {
        //ThanksForPlaying();
    }
}
