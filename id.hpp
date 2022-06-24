#pragma once
#include <string>

class ID {
 public:
  ID() = default;
  ID(const std::string id);
  int numberOfVariationsOfAQuestion(const std::string nameOfFile);

 private:
  std::string id;
};