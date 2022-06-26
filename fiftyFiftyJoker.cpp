#include "fiftyFiftyJoker.hpp"

void FiftyFiftyJoker::useJoker(char correctAnswer, std::string &option1, std::string &option2,
                               std::string &option3, std::string &option4) {

    std::vector<std::string> options = {option1, option2, option3, option4};

    srand(time(nullptr));//setting the seed, from which the randomizer will randomise
    int skipOption = findCorrectAnswerIndex(correctAnswer, option1,
                                            option2, option3, option4);

    int firstDeleteOptionIndex = findFirstOptionToDelete(skipOption);
    int secondDeleteOptionIndex = findSecondOptionToDelete(skipOption, firstDeleteOptionIndex);

    eraseTwoWrongAnswers(firstDeleteOptionIndex, secondDeleteOptionIndex, options);
    takeNewOptions(option1, option2, option3, option4, options);
}

int FiftyFiftyJoker::findCorrectAnswerIndex(char correctAnswer, std::string &option1, std::string &option2,
                                            std::string &option3, std::string &option4) {
    if (option1[0] == correctAnswer) {
        return 1;
    } else if (option2[0] == correctAnswer) {
        return 2;
    } else if (option3[0] == correctAnswer) {
        return 3;
    } else if (option4[0] == correctAnswer) {
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

int FiftyFiftyJoker::findSecondOptionToDelete(int &skipOption, int &firstDeleteOptionIndex) {
    int secondDeleteOptionIndex;
    do {
        secondDeleteOptionIndex = rand() % 4 + 1;
    } while (secondDeleteOptionIndex == firstDeleteOptionIndex || secondDeleteOptionIndex == skipOption);
    return secondDeleteOptionIndex;
}

void FiftyFiftyJoker::eraseTwoWrongAnswers(int &firstDeleteOptionIndex, int &secondDeleteOptionIndex,
                                           std::vector<std::string> &options) {
    for (int i = 0; i < options.size(); ++i) {
        if (firstDeleteOptionIndex == i + 1 || secondDeleteOptionIndex == i + 1) {
            FillingEmptySpace(options[i], options[i].size());
        }
    }
}

void FiftyFiftyJoker::takeNewOptions(std::string &option1, std::string &option2,
                                     std::string &option3, std::string &option4, std::vector<std::string> &options) {
    option1 = options[0];
    option2 = options[1];
    option3 = options[2];
    option4 = options[3];
}
