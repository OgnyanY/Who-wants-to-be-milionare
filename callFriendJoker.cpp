#include "callFriendJoker.hpp"

void CallFriendJoker::callFriend(std::string &possibleAnswers, char &correctAnswer, int &level) {
    srand(time(nullptr));//setting the seed, from which the randomizer will randomise
    int currentMaxPercentage = 100;
    int percentChanceOfLying = calculatePercentChanceOfLying(level);

    int randomNumber = rand() % currentMaxPercentage + 1;

    giveAnswerToQuestion(randomNumber, percentChanceOfLying, possibleAnswers, correctAnswer);
}

int CallFriendJoker::calculatePercentChanceOfLying(int &level) {
    if (level >= 1 && level <= 5) {
        return 30;
    } else if (level >= 6 && level <= 10) {
        return 60;
    } else if (level >= 11 && level <= 15) {
        return 80;
    } else {
        return -1;
    }
}

void CallFriendJoker::giveAnswerToQuestion(int &randomNumber, int &percentChanceOfLying, std::string &possibleAnswers,
                                           char &correctAnswer) {
    if (randomNumber > percentChanceOfLying) {
        giveCorrectAnswer(correctAnswer);
    } else {
        giveWrongAnswer(possibleAnswers, correctAnswer);
    }
}

int CallFriendJoker::getIndexOfCorrectAnswer(std::string &possibleAnswers, char &correctAnswer) {
    int indexOfCorrectAnswer = 0;
    for (int i = 0; i < 4; i++) {
        if (possibleAnswers[i] == correctAnswer) {
            indexOfCorrectAnswer = i;
            break;
        }
    }
    return indexOfCorrectAnswer;
}

void CallFriendJoker::giveWrongAnswer(std::string &possibleAnswers, char &correctAnswer) {
    int optionOneToFour = 0;
    do {
        optionOneToFour = rand() % 3 + 0;
    } while (optionOneToFour == getIndexOfCorrectAnswer(possibleAnswers, correctAnswer));
    std::cout << "\n  Hello, I think that the correct answer should be " << possibleAnswers[optionOneToFour] << '\n';
}

void CallFriendJoker::giveCorrectAnswer(char &correctAnswer) {
    std::cout << "\n  Hello, I think that the correct answer should be " << correctAnswer << '\n';
}
