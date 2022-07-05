#include "editQuestion.hpp"

void EditQuestion::startingMainFunction(){
    writeIdToSearchMessage();
    id.setID(inputIdToSearch());

    if(id.getID() == "0"){
        system("cls");
        return;
    }

    question.loadQuestionAndAnswers(id.fileToSearchIn(), id.getID());
	if(question.getQuestion() == ""){
		return;
	}

	if(askToEditGivenQuestion()){
		enterNewInformation();
		std::vector<std::string> newInformation = loadOldInformationIntoVector();
		writeNewInformationIntoFile(newInformation);
		printSuccessfullyEditedQuestionMessage();
	}
	else{
		system("cls");//clearing console
		return;
	}
}


void EditQuestion::writeIdToSearchMessage(){
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
}

std::string EditQuestion::inputIdToSearch(){
    std::string inputID;
    std::cin >> inputID;
    return inputID;
}

bool EditQuestion::askToEditGivenQuestion(){
	std::system("cls");//clearing console
	printNewLines(6);
	std::cout << "  ========================================== Who wants to be a millionaire? ==========================================\n\n";
	std::cout << "  " << id.getID();
	printNewLines(2);
	std::cout << "  " << question.getQuestion() << '\n';
	printBorder();
	printNewLines(1);
	std::cout << "  Is this the question that you want to edit ? (please type 'y' for yes or 'n' for no)";

	return validInput("yn") == 'y';
}

void EditQuestion::enterNewInformation(){
	NewQuestion newInformation;

	newInformation.writeQuestionGuide(id.topicNumber(), question);
	newInformation.writeAnswersGuide(question);
	newInformation.printQuestionPreview(question, id.topicNumber(), id.getID());
	newInformation.writeCorrectAnswerGuide(question);

	question.setQuestion(questionCheckForNewLine(question.getQuestion()));//checking for new line
}

std::vector<std::string> EditQuestion::loadOldInformationIntoVector(){
	std::vector<std::string> newInformation;

	std::ifstream changeFileInfo(id.fileToSearchIn());

	std::string currentLine;

	while(std::getline(changeFileInfo,currentLine,'\n')){
		if(currentLine == id.getID()){
			break;
		}
		newInformation.push_back(currentLine);
	}
	
	newInformation.push_back(id.getID());
	newInformation.push_back(question.getQuestion());
	newInformation.push_back(question.firstAnswer);
	newInformation.push_back(question.secondAnswer);
	newInformation.push_back(question.thirdAnswer);
	newInformation.push_back(question.forthAnswer);
	newInformation.push_back("\n");
	newInformation.push_back("");
	newInformation[newInformation.size() - 1] += question.getCorrectAnswer();

	for(int i = 0; i < 8; i++){
		std::getline(changeFileInfo,currentLine,'\n');
	}

	while(std::getline(changeFileInfo,currentLine,'\n')){
		newInformation.push_back(currentLine);
	}

	changeFileInfo.close();

	return newInformation;
}

void EditQuestion::writeNewInformationIntoFile(std::vector<std::string> newInformation){
	std::string fileName = id.fileToSearchIn();

	std::ofstream clearFileInfo;
	//delete all previous data in file
	clearFileInfo.open(fileName, std::ofstream::out | std::ofstream::trunc);


	for (int j = 0; j < newInformation.size(); j++) {//add new, edited data in file
		clearFileInfo << newInformation[j] << std::endl;
	}
	clearFileInfo.close();
}

void EditQuestion::printSuccessfullyEditedQuestionMessage(){
	std::system("cls");//clearing console
	printNewLines(6);
	std::cout << "  ========================================== Who wants to be a millionaire? ==========================================\n\n";
	std::cout << "                                      You have successfully edited the question!\n";
	std::cout << "                                   please press any key to return to previous menu!\n";
	printBorder();
	std::cout << "                                         ";
	std::system("pause");
	std::system("cls");//clearing console
}