#ifndef WHO_WANTS_TO_BE_MILIONARE_MAINMENUPAGE_HPP
#define WHO_WANTS_TO_BE_MILIONARE_MAINMENUPAGE_HPP

#include <iostream>
#include <windows.h>
#include <cstdlib>

//#include "editQuestion.hpp"
#include "newGame.hpp"
#include "newQuestion.hpp"
#include "usefulFunctions.hpp"

class MainMenuPage {
public:
    MainMenuPage() = default;

    void createMainMenuPage();

private:
    char choice = '\0';

    void printMainMenuPage();

    void makeChoiceInMenu(char menuChoice);
};

#endif //WHO_WANTS_TO_BE_MILIONARE_MAINMENUPAGE_HPP
