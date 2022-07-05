#include "question.hpp"

void Question::printQuestionAndAnswers() {
    std::cout << ID_of_question << '\n'
              << question << '\n'
              << firstAnswer << '\n'
              << secondAnswer << '\n'
              << thirdAnswer << '\n'
              << forthAnswer << '\n';
    std::cout << '\n';
}

void Question::loadQuestionAndAnswers(const std::string nameOfFile,
                                      const std::string ID) {
    std::ifstream currentLine(nameOfFile);

    if (!currentLine.is_open()) {
        std::cout << "file is not open!";
        return;
    }

    while (std::getline(currentLine, ID_of_question, '\n')) {
        if (ID_of_question == ID) {
            break;
        }
    }
    if(currentLine.eof()){
        printCantLoadQuestionAndAnswersMessage();
    }
    else{
        std::getline(currentLine, question, '\n');
        std::getline(currentLine, firstAnswer, '\n');
        std::getline(currentLine, secondAnswer, '\n');
        std::getline(currentLine, thirdAnswer, '\n');
        std::getline(currentLine, forthAnswer, '\n');

        currentLine.ignore();
        std::getline(currentLine, correctAnswer, '\n');
    }

    currentLine.close();
}

std::string Question::correctFullAnswer() const {
    if (correctAnswer[0] == firstAnswer[0]) {
        return firstAnswer;
    } else if (correctAnswer[0] == secondAnswer[0]) {
        return secondAnswer;
    } else if (correctAnswer[0] == thirdAnswer[0]) {
        return thirdAnswer;
    } else {
        return forthAnswer;
    }
}

char Question::getCorrectAnswer() const { return correctAnswer[0]; }

void Question::setCorrectAnswer(char newAnswer) { correctAnswer = newAnswer; }

std::string Question::getQuestion() const { return question; }

void Question::setQuestion(std::string newQuestion) { question = newQuestion; }

void printCantLoadQuestionAndAnswersMessage(){
    std::system("cls");//clearing console
	printNewLines(6);
	std::cout << "  ========================================== Who wants to be a millionaire? ==========================================\n\n";
	std::cout << "                                It appears that a question with this ID does not exists,\n";
	std::cout << "                                      please press any key to return to previous menu!\n";
	printBorder();
	std::cout << "                                         ";
	std::system("pause");
	std::system("cls");//clearing console
}





