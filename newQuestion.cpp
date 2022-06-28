#include "newQuestion.hpp"

void NewQuestion::EnteringNewQuestion() {
    char categoryChoice = selectingCategory(choiceSelection);

    std::string topic = selectTopic(categoryChoice);
    if(topic == "return"){
        return;
    }

    int diffChoice = selectingDifficultyOfQuestion(numberOfQuestionChoices);

    ID questionID;
    generateID(questionID,diffChoice,topic,categoryChoice);

    Question question;
    generateQuestion(question,questionID,diffChoice,topic);

    printSuccessfulNewQuestion();
}

void NewQuestion::printSuccessfulNewQuestion() {
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

void NewQuestion::enteringNewInfoIntoFile(const std::string &fileName, const Question &question,
                                          int &numberOfQuestion, const std::string &fullID) {
    std::ofstream NewQuestion(fileName, std::ios::app);//append, starts the typing from the end of the file

    NewQuestion << '\n' << '\n' << fullID << '\n';//inserting each string that has been saved
    NewQuestion << numberOfQuestion << ". " << question.getQuestion() << "?" << '\n';
    NewQuestion << "A) " << question.firstAnswer << '\n';
    NewQuestion << "B) " << question.secondAnswer << '\n';
    NewQuestion << "C) " << question.thirdAnswer << '\n';
    NewQuestion << "D) " << question.forthAnswer << '\n' << '\n';
    NewQuestion << question.getCorrectAnswer() << '\n';

    NewQuestion.close();
}

void NewQuestion::writingNewQuestionAnswers(Question &question, int &diffChoice, std::string fullQuestionID) {

    writeQuestionGuide(diffChoice,question);

    writeAnswersGuide(question);

    printQuestionPreview(question,diffChoice,fullQuestionID);

    writeCorrectAnswerGuide(question);
}

int NewQuestion::selectingDifficultyOfQuestion(std::vector<int> &numberOfQuestionChoices) {
    printSelectingDifficultyOfQuestion();
    int answer = validInput(numberOfQuestionChoices);
    system("cls");//clearing console
    return answer;
}

void NewQuestion::printSelectingDifficultyOfQuestion() {
    printNewLines(6);
    std::cout << "  ========================================== Who wants to be a millionaire? ==========================================\n\n";
    std::cout << "  Select number of question 1-15 (form 1 to 15)\n\n";
    std::cout << "  Usually questions:    1-5 are considered to be with easy difficulty\n";
    std::cout << "                        6-10 are considered to be with avarage difficulty\n";
    std::cout << "                        11-15 are considered to be with hard difficulty\n";
    printBorder();
    std::cout << "\n\n  Please enter the number of your choice: ";
}

char NewQuestion::selectingCategory(const std::string& choiceSelection) {
    printSelectingCategory();
    char answer = validInput(choiceSelection);
    system("cls");//clearing console
    return answer;
}

void NewQuestion::printSelectingCategory() {
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

std::string NewQuestion::selectTopic(char &choice) {
    if (choice == '1') {
        return "topics/Life.txt";

    } else if (choice == '2') {
        return "topics/History.txt";

    } else if (choice == '3') {
        return "topics/Cinema.txt";

    } else if (choice == '4') {
        return "topics/Sports.txt";

    } else if (choice == '5') {
        return "topics/Politics.txt";

    } else if (choice == '0') {
        system("cls");//clearing console
        return "return";
    }
    else{
        return "NULL";
    }
}

void NewQuestion::generateID(ID &questionID,int diffChoice,const std::string& topic, char categoryChoice) {
    questionID.firstTwoDigitsIDGenerator(diffChoice);

    int additionalQuestion = questionID.numberOfVariationsOfAQuestion(topic) + 1;

    questionID.lastFiveDigitsIDGenerator(categoryChoice,additionalQuestion);
}

void NewQuestion::generateQuestion(Question &question, ID &questionID, int diffChoice,
                                       const std::string &topic) {
    writingNewQuestionAnswers(question, diffChoice, questionID.getID());

    question.setQuestion(questionCheckNewLine(question.getQuestion()));//checking for new line

    enteringNewInfoIntoFile(topic,question,diffChoice, questionID.getID());
}

void NewQuestion::writeQuestionGuide(int diffChoice, Question &question) {
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

void NewQuestion::writeAnswersGuide(Question &question) {
    printNewLines(6);
    std::cout << "  ========================================== Who wants to be a millionaire? ==========================================\n\n";
    std::cout << "  Please write your optional answers below:  (after completing the answer, press 'Enter' to continue to the next one)\n";
    std::cout << "  (each answer can hold up to 100 symbols)\n";
    std::cout << '\n';
    printBorder();
    char garbage[3] = {'\0'};//using this to suck the incoming new line from entering question
    std::cin.getline(garbage, 2, '\n');

    std::cout << "\n  " << "A) ";
    std::getline(std::cin, question.firstAnswer, '\n');
    std::cout << "  " << "B) ";
    std::getline(std::cin, question.secondAnswer, '\n');
    std::cout << "  " << "C) ";
    std::getline(std::cin, question.thirdAnswer, '\n');
    std::cout << "  " << "D) ";
    std::getline(std::cin, question.forthAnswer, '\n');

    system("cls");//clearing console
}

void NewQuestion::printQuestionPreview(const Question &question, int &diffChoice, const std::string &fullQuestionID) {
    printNewLines(6);
    std::cout << "  ========================================== Who wants to be a millionaire? ==========================================\n\n";
    std::cout << "  ID of question: " << fullQuestionID << '\n';
    std::cout << "  " << diffChoice << ". " << question.getQuestion() << "?\n\n";
    std::cout << "  A) " << question.firstAnswer << '\n';
    std::cout << "  B) " << question.secondAnswer << '\n';
    std::cout << "  C) " << question.thirdAnswer << '\n';
    std::cout << "  D) " << question.forthAnswer << '\n';

    std::cout << '\n';
    printBorder();
}

void NewQuestion::writeCorrectAnswerGuide(Question &question) {
    std::cout << "  Which one is the correct answer? : (A, B, C or D)";
    char correctAnswer = question.getCorrectAnswer();
    do {
        std::cin >> correctAnswer;
    } while (correctAnswer != 'A' && correctAnswer != 'B' && correctAnswer != 'C' && correctAnswer != 'D');
    question.setCorrectAnswer(correctAnswer);

    system("cls");//clearing console
}
