#include "newQuestion.hpp"

void newQuestion::EnteringNewQuestion() {
    std::string choiceSelection = {'1', '2', '3', '4', '5', '0'};
    char categoryChoice = selectingCategory(choiceSelection);

    std::string topic = selectTopic(categoryChoice);
    if(topic == "return"){
        return;
    }
    system("cls");//clearing console

    std::vector<int> numberOfQuestionChoices = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int diffChoice = selectingDifficultyOfQuestion(numberOfQuestionChoices);
    system("cls");//clearing console

    ID questionID;
    questionID.firstTwoDigitsIDGenerator(diffChoice);

    int timesQuestionExists = 0;
    //searching how many times there is a question with this number  example: 2.
    searchHowManyPossibleQuestions(topic, timesQuestionExists, questionID.getID());

    int additionalQuestion = timesQuestionExists + 1;//the last 3 digits of the new question id

    questionID.lastFiveDigitsIDGenerator(categoryChoice,additionalQuestion);

    Question question;
    writingNewQuestionAnswers(question, diffChoice, questionID.getID());

    question.setQuestion(questionCheckNewLine(question.getQuestion()));//checking for new line

    enteringNewInfoIntoFile(topic, question.getQuestion(), question.firstAnswer, question.secondAnswer,
                            question.thirdAnswer, question.forthAnswer, question.getCorrectAnswer(),
                            diffChoice, questionID.getID());

    printSuccessfulNewQuestion();
}

void newQuestion::printSuccessfulNewQuestion() {
    printNewLines(6);
    std::cout << "  ========================================== Who wants to be a millionaire? ==========================================\n\n";
    std::cout << "                                                   Congratulations!\n\n";
    std::cout << "                                        You have successfully added new question!\n";
    std::cout << '\n';
    printBorder();
    std::cout << '\n';
    system("pause");//pausing console
    system("cls");//clearing console
}

void newQuestion::enteringNewInfoIntoFile(const std::string &fileName, const std::string &question,
                                          const std::string &option1, const std::string &option2,
                                          const std::string &option3, const std::string &option4,
                                          char correctAnswer, int &numberOfQuestion, const std::string &fullID) {
    std::ofstream NewQuestion(fileName, std::ios::app);//append, starts the typing from the end of the file

    NewQuestion << '\n' << '\n' << fullID << '\n';//inserting each string that has been saved
    NewQuestion << numberOfQuestion << ". " << question << "?" << '\n';
    NewQuestion << "A) " << option1 << '\n';
    NewQuestion << "B) " << option2 << '\n';
    NewQuestion << "C) " << option3 << '\n';
    NewQuestion << "D) " << option4 << '\n' << '\n';
    NewQuestion << correctAnswer << '\n';

    NewQuestion.close();
}

void newQuestion::writingNewQuestionAnswers(Question &question, int &diffChoice, std::string fullQuestionID) {

    writeQuestionGuide(diffChoice,question);

    writeAnswersGuide(question.firstAnswer, question.secondAnswer,
                      question.thirdAnswer, question.forthAnswer);

    printQuestionPreview(question.getQuestion(),question.firstAnswer, question.secondAnswer,
                         question.thirdAnswer, question.forthAnswer,question.getCorrectAnswer(),diffChoice,fullQuestionID);

    writeCorrectAnswerGuide(question);
}

int newQuestion::selectingDifficultyOfQuestion(std::vector<int> &numberOfQuestionChoices) {
    printSelectingDifficultyOfQuestion();

    return validInput(numberOfQuestionChoices);
}

void newQuestion::printSelectingDifficultyOfQuestion() {
    printNewLines(6);
    std::cout << "  ========================================== Who wants to be a millionaire? ==========================================\n\n";
    std::cout << "  Select number of question 1-15 (form 1 to 15)\n\n";
    std::cout << "  Usually questions:    1-5 are considered to be with easy difficulty\n";
    std::cout << "                        6-10 are considered to be with avarage difficulty\n";
    std::cout << "                        11-15 are considered to be with hard difficulty\n";
    printBorder();
    std::cout << "\n\n  Please enter the number of your choice: ";
}

char newQuestion::selectingCategory(const std::string& choiceSelection) {
    printSelectingCategory();
    return validInput(choiceSelection);
}

void newQuestion::printSelectingCategory() {
    printNewLines(6);
    std::cout << "  ========================================== Who wants to be a millionaire? ==========================================\n\n";
    std::cout << "  Enter which category, you want your question to be in:\n\n";
    std::cout << "  1. Life\n";
    std::cout << "  2. History\n";
    std::cout << "  3. Cinema\n";
    std::cout << "  4. Sports\n";
    std::cout << "  5. Politics\n\n";
    std::cout << "  0. For exiting and going back to the Main Menu\n";
    printBorder();
    std::cout << "\n\n  Please enter the number of your choice: ";
}

std::string newQuestion::selectTopic(char &choice) {
    if (choice == '1') {
        return "Life.txt";

    } else if (choice == '2') {
        return "History.txt";

    } else if (choice == '3') {
        return "Cinema.txt";

    } else if (choice == '4') {
        return "Sports.txt";

    } else if (choice == '5') {
        return "Politics.txt";

    } else if (choice == '0') {
        system("cls");//clearing console
        return "return";
    }
    else{
        return "NULL";
    }
}

void newQuestion::searchHowManyPossibleQuestions(const std::string &nameOfFile, int &timesQuestionExists,
                                                 std::string questionID) {
    std::ifstream questionFile(nameOfFile);
    std::string printingString; //creating a char array, that will compare later
    const int SIZE_OF_ROW = 1000;
    char gettingLine[SIZE_OF_ROW];
    while (questionFile.getline(gettingLine, SIZE_OF_ROW)) {//getting the whole line
        for (int i = 0; i < 6; i++) {
            printingString[i] = gettingLine[i];//rewriting the first 5 symbols to a new char array
        }
        printingString[5] = '\0';//adding manual terminating zero to the last element

        bool isSame = true;//creating a flag that will signal if the arrays are equal(the IDs)
        for (int i = 0; i < 5; i++) {
            if (printingString[i] != questionID[i]) {
                isSame = false;
                break;
            }
        }
        if (isSame) {
            timesQuestionExists++;//giving the integer +1 to its value
        }
    }
    questionFile.close();//closing file
}

void newQuestion::writeQuestionGuide(int diffChoice, Question &question) {
    printNewLines(6);
    std::cout << "  ========================================== Who wants to be a millionaire? ==========================================\n\n";
    std::cout << "  Please write your question below:  (please dont forget to add '?' at the end)\n  (question can hold up to 1000 symbols)\n";
    std::cout << '\n';
    printBorder();
    std::cout << "\n  " << diffChoice << ". ";

    //using this to catch the new line symbol from the buffer,
    // that's caused because of previous validation of cin
    if (std::cin.peek() == '\n') {
        std::cin.get();
    }

    std::string newQuestion = question.getQuestion();
    std::getline(std::cin,newQuestion,'?');
    question.setQuestion(newQuestion);

    system("cls");//clearing console
}

void newQuestion::writeAnswersGuide(std::string &option1, std::string &option2,
                                    std::string &option3, std::string &option4) {
    printNewLines(6);
    std::cout << "  ========================================== Who wants to be a millionaire? ==========================================\n\n";
    std::cout << "  Please write your optional answers below:  (after completing the answer, press 'Enter' to continue to the next one)\n";
    std::cout << "  (each answer can hold up to 100 symbols)\n";
    std::cout << '\n';
    printBorder();
    char garbage[3] = {'\0'};//using this to suck the incoming new line from entering question
    std::cin.getline(garbage, 2, '\n');

    std::cout << "\n  " << "A) ";
    std::getline(std::cin, option1, '\n');
    std::cout << "  " << "B) ";
    std::getline(std::cin, option2, '\n');
    std::cout << "  " << "C) ";
    std::getline(std::cin, option3, '\n');
    std::cout << "  " << "D) ";
    std::getline(std::cin, option4, '\n');

    system("cls");//clearing console
}

void newQuestion::printQuestionPreview(const std::string& question,
                                       const std::string& option1, const std::string& option2,
                                       const std::string& option3, const std::string& option4,
                                       char correctAnswer, int &diffChoice, const std::string &fullQuestionID) {
    printNewLines(6);
    std::cout << "  ========================================== Who wants to be a millionaire? ==========================================\n\n";
    std::cout << "  ID of question: " << fullQuestionID << '\n';
    std::cout << "  " << diffChoice << ". " << question << "?\n\n";
    std::cout << "  A) " << option1 << '\n';
    std::cout << "  B) " << option2 << '\n';
    std::cout << "  C) " << option3 << '\n';
    std::cout << "  D) " << option4 << '\n';

    std::cout << '\n';
    printBorder();
}

void newQuestion::writeCorrectAnswerGuide(Question &question) {
    std::cout << "  Which one is the correct answer? : (A, B, C or D)";
    char correctAnswer = question.getCorrectAnswer();
    do {
        std::cin >> correctAnswer;
    } while (correctAnswer != 'A' && correctAnswer != 'B' && correctAnswer != 'C' && correctAnswer != 'D');
    question.setCorrectAnswer(correctAnswer);

    system("cls");//clearing console
}

