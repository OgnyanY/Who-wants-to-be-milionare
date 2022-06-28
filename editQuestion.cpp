//
// Created by Acer on 26.6.2022 г..
//

#include "editQuestion.hpp"

void EditQuestion::EditingExistingQuestion() {
    std::string searchQuestionID = {'\0' };
    char exitSymbol = '0';//entering this symbol when you want to leave menu
    std::string fileName = { '\0' };

    do {
        AskForID(searchQuestionID, exitSymbol, fileName);
        if ((searchQuestionID[0] == exitSymbol) && (searchQuestionID[1] == '\0')) {//asking over and over again
            return;
        }
    } while (searchQuestionID[0] != exitSymbol);

}

void EditQuestion::AskForID(std::string &searchQuestionID, char exitSymbol, std::string &fileName) {
    std::string detZero = { '\0' };//array which is used to fill another array with det. zeros

    bool questionExists = false;//flag if question exists

    questionExists = false;

    searchQuestionID = detZero;//filling array with det. zeros
    askForIDGuide(searchQuestionID);

    if ((searchQuestionID[0] == exitSymbol) && (searchQuestionID[1] == '\0')) {//check if 0 is input, return to previous menu
        system("cls");//clearing console
        return;
    }
    SearchIDInFiles(searchQuestionID, detZero, fileName, questionExists);//searching for entered ID
}

void EditQuestion::askForIDGuide(std::string &searchQuestionID) {
    printNewLines(6);
    std::cout << "  ========================================== Who wants to be a millionaire? ==========================================\n\n";
    std::cout << "  Please insert the ID of the question that you want to edit: ID:XX-YYZZZ\n";
    std::cout << "  XX stands for number of question (1-15)\n";
    std::cout << "  YY stands for topic of question: (1 - Life; 2 - History; 3 - Cinema; 4 - Sports; 5 - Politics\n";
    std::cout << "  ZZZ stands for number of recurring question\n\n";
    std::cout << "  Example: ID:01-01001\n\n";
    std::cout << "  Enter 0 to return to Main Menu:\n";
    printBorder();
    std::cout << "\n  Enter ID of question or '0': ";
    std::cin >> searchQuestionID;
}

void EditQuestion::SearchIDInFiles(std::string &searchQuestionID, const std::string& detZero,
                                   std::string &fileName, bool &questionExists) {
    char newQuestion[1000] = { '\0' };//declaring question and answers
    char newOption1[100] = { '\0' };
    char newOption2[100] = { '\0' };
    char newOption3[100] = { '\0' };
    char newOption4[100] = { '\0' };
    char newCorrectAnswer = '\0';

    std::vector<std::string> editQuestionFile;//declaring a vector, where we will store the information and will change the question and answers

    for (int i = 1; i <= 5; i++) {//going through all the files, because if the ID doesn't contain in one file, it may contain in another
        //CopyStr(detZero, fileName);
        fileName = detZero;
        pickFileName(fileName, i);

        int lineCounter = 0;//checking on which line we want to enter new question and answers
        std::ifstream editFile(fileName);//don't forget to close file
        //const int ID_SIZE = 12;
        //char possibleID[ID_SIZE] = { '\0' };

        //const int SIZE_OF_ROW = 1000;
        std::string currentLine;//declaring char array, where we will drag the information from each line
        while (std::getline(editFile,currentLine)) {
            lineCounter++;//adding counter
            //for (int j = 0; j < 11; j++) {//if the ID's are equal, change the flag that this question exists
                if (searchQuestionID == currentLine) {
                    questionExists = true;
                    //continue;
                }
                else {
                    questionExists = false;//if any of the symbols does not match, break the loop, continue with the next one and start the inner loop again
                    //break;
                }
            //}
            if (!questionExists) {//if any of the symbols does not match, break the loop, continue with the next one and start the inner loop again
                continue;
            }
            else {//if this question exists, print the question and ask user if that's the question that he wants to edit
                std::getline(editFile,currentLine);
                char ynOption = { '\0' };
                ///ProperNewLineToString(currentLine);//adding manually new line when a word is about to break between 2 lines
                system("cls");//clearing console
                printNewLines(6);
                std::cout << "  ========================================== Who wants to be a millionaire? ==========================================\n\n";
                std:: cout << "  " << searchQuestionID;
                printNewLines(2);
                std::cout << "  " << currentLine << '\n';
                printBorder();
                printNewLines(1);
                std::cout << "  Is this the question that you want to edit ? (please type 'y' for yes or 'n' for no)";
                std::cin >> ynOption;
                while (ynOption != 'y' && ynOption != 'n') {
                    std::cin >> ynOption;
                }
                if (ynOption == 'n') {//if answer is no, return to previous menu
                    editFile.close();
                    system("cls");//clearing console
                    return;
                }
                else if (ynOption == 'y') {//if yes turn the first digits of id into int
                    system("cls");//clearing console
                    int NumberQuestion = 0;
                    //turn the first digits of id into int
                    if (searchQuestionID[3] == '0') {
                        NumberQuestion = searchQuestionID[4] - '0';
                    }
                    else {
                        int afterNumber = searchQuestionID[4] - '0';
                        NumberQuestion = searchQuestionID[3] - '0';
                        NumberQuestion = (NumberQuestion * 10) + afterNumber;
                    }
                    //ask user to writhe question + 4 options + correct answer
                    //writingNewQuestionAnswers(newQuestion, newOption1, newOption2, newOption3, newOption4, newCorrectAnswer, NumberQuestion, searchQuestID);
                    questionCheckForNewLine(newQuestion);//check if there is a new line, if yes, swap it for empty space
                    /*int newQestLength = StrLength(newQuestion);//getting lengths string of all strings
                    int newOpt1Length = StrLength(newOption1);
                    int newOpt2Length = StrLength(newOption2);
                    int newOpt3Length = StrLength(newOption3);
                    int newOpt4Length = StrLength(newOption4);*/

                    //add manually the number of question before actual question, depending if the number is a 2 digit or 1 digit
                    if (searchQuestionID[3] == '0') {
                        char newLinequest[4] = "";
                        char addNumberQuest[5] = "X. ";
                        addNumberQuest[0] = searchQuestionID[4];
                        //AddAdditonalCharacters(newQuestion, newQestLength, addNumberQuest);
                    }
                    else {
                        char addNumberQuest[6] = "XX. ";
                        addNumberQuest[0] = searchQuestionID[3];
                        addNumberQuest[1] = searchQuestionID[4];
                        //AddAdditonalCharacters(newQuestion, newQestLength, addNumberQuest);
                    }
                    //adding options to availabe options ( A)  )
                    char nOpt1[5] = "A) ";
                    //AddAdditonalCharacters(newOption1, newOpt1Length, nOpt1);
                    char nOpt2[5] = "B) ";
                    //AddAdditonalCharacters(newOption2, newOpt2Length, nOpt2);
                    char nOpt3[5] = "C) ";
                    //AddAdditonalCharacters(newOption3, newOpt3Length, nOpt3);
                    char nOpt4[5] = "D) ";
                    //AddAdditonalCharacters(newOption4, newOpt4Length, nOpt4);

                    editFile.close();//break the loop and close file
                    break;

                }
            }
        }
        if (questionExists == false) {//if the ID doesn't match with any other, close the current file and move to the next one
            editFile.close();
            continue;
        }
        std::fstream changeFileInfo(fileName);//opening again

        while (std::getline(changeFileInfo, currentLine)) {//writing information into string vector
            editQuestionFile.push_back(currentLine);
        }

        //manually change question + answers
        editQuestionFile[lineCounter] = newQuestion;
        editQuestionFile[lineCounter + 1] = newOption1;
        editQuestionFile[lineCounter + 2] = newOption2;
        editQuestionFile[lineCounter + 3] = newOption3;
        editQuestionFile[lineCounter + 4] = newOption4;
        editQuestionFile[lineCounter + 6] = newCorrectAnswer;//here skip 1 line, because this line is empty and move to the next one (6)

        changeFileInfo.close();//close file

        std::ofstream clearFileInfo;//open file again
        clearFileInfo.open(fileName, std::ofstream::out | std::ofstream::trunc);//delete all previous data in file

        for (int j = 0; j < editQuestionFile.size(); j++) {//add new, edited data in file
            clearFileInfo << editQuestionFile[j] << '\n';
        }

        clearFileInfo.close();//close file
        //printing successfull editing
        system("cls");//clearing console
        printNewLines(6);
        std::cout << "  ========================================== Who wants to be a millionaire? ==========================================\n\n";
        std::cout << "                                      You have successfully edited the question!\n";
        std::cout << "                                   please press any key to return to previous menu!\n";
        printBorder();
        std::cout << "                                         ";
        system("pause");
        system("cls");//clearing console
        return;
    }
    if (questionExists == false) {//if there wasn't a ID that's contained in the files print that a question with this ID does not exists
        system("cls");//clearing console
        printNewLines(6);
        std::cout << "  ========================================== Who wants to be a millionaire? ==========================================\n\n";
        std::cout << "                                It appears that a question with this ID does not exists,\n";
        std::cout << "                                      please press any key to return to previous menu!\n";
        printBorder();
        std::cout << "                                         ";
        system("pause");
        system("cls");//clearing console
    }
}

void EditQuestion::pickFileName(std::string &fileName, int number) {
    if (number == 1) {
        fileName = "Life.txt";
    }
    else if (number == 2) {
        fileName = "History.txt";
    }
    else if (number == 3) {
        fileName = "Cinema.txt";
    }
    else if (number == 4) {
        fileName = "Sports.txt";
    }
    else {
        fileName = "Politics.txt";
    }
}
