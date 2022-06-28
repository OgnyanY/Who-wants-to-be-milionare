#pragma once

#include <string>
#include <fstream>
#include <iostream>

#include "usefulFunctions.hpp"

class ID {
public:
    ID();

    ID(const std::string id);

    std::string getID();

    void setID(std::string newId);

    int numberOfVariationsOfAQuestion(const std::string nameOfFile);

    void firstTwoDigitsIDGenerator(int level);

    void lastFiveDigitsIDGenerator(const int topicChoice, int number);

private:
    std::string id;
};