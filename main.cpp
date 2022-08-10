#include <algorithm>
#include <iostream>
#include <limits> //import std::numeric_limits
#include <random>
#include <vector>


// config for generate random number
namespace Config {
  constexpr int minNumber{2};
  constexpr int maxNumber{4};
}

void ignoreLine(){
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
}

// get base number from user
int getBaseSquareNumber(){
  int baseNumber{};
  do {
    std::cout << "Start where? ";
    std::cin >> baseNumber;
    if(!std::cin){
      std::cin.clear();
      ignoreLine();
    }
  } while(baseNumber <= 0);
  return baseNumber;
}

// get the amount of numbers to generate
int getNumberToGenerate() {
  int num{};
  do {
    std::cout << "How many? ";
    std::cin >> num;
    if(!std::cin){
      std::cin.clear();
      ignoreLine();
    }
  } while(num <= 0);
  return num;
}

// generate random number between 2 and 4
namespace Random {
  std::random_device rd;
  std::seed_seq sq{rd(),rd(),rd(),rd(),rd(),rd(),rd(),rd()};
  std::mt19937 mt{sq};

  int getRandomNumber(int min, int max){
    std::uniform_int_distribution<> die{min, max};
    return die(mt);
  }
}

std::vector<int> listNum(int baseNumber,int amountOfNumbers) {
  std::vector<int> temp{};
  temp.resize(amountOfNumbers);
  std::vector<int>::size_type total{};
  for(auto& number:temp){
    total = number * baseNumber * Random::getRandomNumber(Config::minNumber, Config::maxNumber);
  }
  return temp;
}

int main() {

  auto baseNumber{getBaseSquareNumber()};
  auto amountOfNumbers{getNumberToGenerate()};

  return 0;
}
