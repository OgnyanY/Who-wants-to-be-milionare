#include "usefulFunctions.hpp"

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

char levelFromIntToChar(int level) {
    return '0' + level;
}

void printNewLines(int number) {
    for (int i = 0; i < number; i++) {
        cout << '\n';
    }
}

void printEmptySpaces(int number) {
    for (int i = 0; i < number; i++) {
        cout << ' ';
    }
}

void printBorder() {
    cout << endl;
    cout << setw(3);
    const int SIZE_OF_CONSOLE_ROW = 120;
    for (int i = 0; i < (SIZE_OF_CONSOLE_ROW - 4); i++) {
        cout << '=';
    }
    cout << endl;
}

char validInput(const std::string &str) {
    bool validChoice = false;
    char number;
    do {
        cin >> number;
        for (int i = 0; i < str.size(); i++) {
            if (number != str[i]) {
                continue;
            }
            validChoice = true;
            break;
        }
        if (!validChoice) {
            std::cout << "Invalid choice!\n";
        }
    } while (!validChoice);
    return number;
}

int validInput(const std::vector<int> &arr) {
    bool validChoice = false;
    int number;
    do {
        std::cin >> number;
        for (int i = 0; i < arr.size(); i++) {
            if (number != arr[i]) {
                continue;
            }
            validChoice = true;
            break;
        }
        if (!validChoice) {
            std::cout << "Invalid choice!\n";
        }
    } while (!validChoice);
    return number;
}

void fillingWithEmptySpace(std::string &option, int optionSize) {
    for (int i = 0; i < optionSize; i++) {
        option[i] = ' ';
    }
    option[optionSize] = '\0';
}

void thanksForPlaying() {  // exiting message
    printNewLines(6);
    printBorder();
    cout << "\n\n                                         Thanks for playing, have a nice day !\n\n";

    printNewLines(6);
}

// if in the inserted new question somewhere is
// a symbol for new line, turns it into empty space
std::string questionCheckForNewLine(std::string question) {
    for (int i = 0; i < question.size(); i++) {
        if (question[i] == '\n') {
            question[i] = ' ';
        }
    }
    return question;
}