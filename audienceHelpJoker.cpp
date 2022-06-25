#include "audienceHelpJoker.hpp"

void AudienceHelpJoker::useJoker(std::string &possibleAnswers, char &correctAnswer, int &level) {
    srand(time(nullptr));//setting the seed, from which the randomizer will randomise
    int currentMaxPercentage = 100;
    int percentChanceOfLying = calculatePercentChanceOfLying(level);

    int randomNumber = rand() % currentMaxPercentage + 1;

    giveAnswerToQuestion(randomNumber, percentChanceOfLying, possibleAnswers, correctAnswer);
}

int AudienceHelpJoker::calculatePercentChanceOfLying(int &level) {
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

void AudienceHelpJoker::giveAnswerToQuestion(int &randomNumber, int &percentChanceOfLying, std::string &possibleAnswers,
                                             char &correctAnswer) {
    if (randomNumber > percentChanceOfLying) {//deciding if the number rolled over the "percentChanceOfLying"
        giveCorrectAnswer(correctAnswer);
    }
    else {
        giveWrongAnswer(possibleAnswers,correctAnswer);
    }
}

int AudienceHelpJoker::getIndexOfCorrectAnswer(std::string &possibleAnswers, char &correctAnswer) {
    int indexOfCorrectAnswer = 0;
    for (int i = 0; i < 4; i++) {
        if (possibleAnswers[i] == correctAnswer) {
            indexOfCorrectAnswer = i;
            break;
        }
    }
    return indexOfCorrectAnswer;
}

void AudienceHelpJoker::giveWrongAnswer(std::string &possibleAnswers, char &correctAnswer) {
    int optionOneToFour = 0;
    do {
        optionOneToFour = rand() % 4 + 0;
    } while (optionOneToFour == getIndexOfCorrectAnswer(possibleAnswers, correctAnswer));
    std::cout << "\n  The audience has decided! They think that the correct answer is "
              << possibleAnswers[optionOneToFour] << '\n';
}

void AudienceHelpJoker::giveCorrectAnswer(char &correctAnswer) {
    std::cout << "\n  The audience has decided! They think that the correct answer is " << correctAnswer << '\n';
}
