#include "audienceHelpJoker.hpp"

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
