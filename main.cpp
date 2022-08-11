#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits> //import std::numeric_limits
#include <random> // std::mt19937, std::seed_seq, std::random_device, std::uniform_int_distribution
#include <vector> // import std::vector and std::vector::size_type


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

using list_num = std::vector<int>;
using index_type = list_num::size_type;

list_num getListNum(int baseNumber,int amountOfNumbers, int randomNumber) {
  list_num listNums{};
  listNums.resize(static_cast<index_type>(amountOfNumbers));
  index_type lenght{static_cast<index_type>(std::size(listNums))};
  for(index_type count{};count < lenght;++count) {
    listNums[count] = (baseNumber) * (baseNumber) * randomNumber;
    ++baseNumber;
  }
  return listNums;
}

bool playGame() {

}

int main() {

  auto baseNumber{getBaseSquareNumber()};
  auto amountOfNumbers{getNumberToGenerate()};
  auto randomNumber{getNumberToGenerate()};

  auto get{getListNum(baseNumber, amountOfNumbers,randomNumber)};

  for(const auto& i:get) {
    std::cout << i << ' ';
  }
  std::cout << '\n';

  return 0;
}
