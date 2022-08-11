#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits> // import std::numeric_limits
#include <random> // import std::mt19937, std::seed_seq, std::random_device, std::uniform_int_distribution
#include <vector> // import std::vector and std::vector::size_type

// config for generate random number
namespace Config {
constexpr int minNumber{2};
constexpr int maxNumber{4};
} // namespace Config

void ignoreLine() {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// get base number from user
int getBaseSquareNumber() {
  int baseNumber{};
  do {
    std::cout << "Start where? ";
    std::cin >> baseNumber;
    if (!std::cin) {
      std::cin.clear();
      ignoreLine();
    }
  } while (baseNumber <= 0);
  return baseNumber;
}

// get the amount of numbers to generate
int getNumberToGenerate() {
  int num{};
  do {
    std::cout << "How many? ";
    std::cin >> num;
    if (!std::cin) {
      std::cin.clear();
      ignoreLine();
    }
  } while (num <= 0);
  return num;
}

int getGues() {
  while (true) {
   int guess{};
   std::cout << "> ";
   std::cin >> guess;
   if(!std::cin) {
     std::cin.clear();
     ignoreLine();
   }else {
    ignoreLine();
    return guess;
   }
  }
}

// generate random number between 2 and 4
namespace Random {
std::random_device rd;
std::seed_seq sq{rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};
std::mt19937 mt{sq};

int getRandomNumber(int min, int max) {
  std::uniform_int_distribution<> die{min, max};
  return die(mt);
}
} // namespace Random

using list_num = std::vector<int>;
using index_type = list_num::size_type;

list_num getListNum(int baseNumber, int totalNumbers, int randomNumber) {
  list_num listNums{};
  listNums.resize(static_cast<index_type>(totalNumbers));
  index_type lenght{static_cast<index_type>(std::size(listNums))};
  for (index_type count{}; count < lenght; ++count) {
    listNums[count] = (baseNumber) * (baseNumber)*randomNumber;
    ++baseNumber;
  }
  return listNums;
}

bool player(list_num numbers,int totalNumbers, int randomNumber) {
  std::cout << "I generated " << totalNumbers << " square numbers. Do you know each number is after multiplying by " << randomNumber << '\n';
  int count{0};
  while (count < totalNumbers) {
    int guess{getGues()};
    auto found{std::find(numbers.begin(),numbers.end(),guess)};
    --totalNumbers;
    if (found == numbers.end())
    {
        auto num{std::min_element(numbers.begin(),numbers.end(),[](const auto& a,const auto& b){
        return (a < b);
        })};
      std::cout << guess << " was not found\n";
      std::cout << "try " << *num << " next time\n";
      return true;
    }else {
      if (totalNumbers == 0) {
        break;
      }
      std::cout << "Nice " << totalNumbers << " numbers left\n";
      numbers.erase(found);
    }
  }
    return false;
}

bool playGame() {
  int baseNumber{getBaseSquareNumber()};
  int totalNumbers{getNumberToGenerate()};
  int randomNumber{Random::getRandomNumber(Config::minNumber, Config::maxNumber)};
  list_num numbers{getListNum(baseNumber, totalNumbers, randomNumber)};
  for(const auto& i:numbers) {
    std::cout << i << ' ';
  }
  std::cout << '\n';
  if (player(numbers, totalNumbers, randomNumber))
  {
    return false;
  }
  return true;
}

int main() {

  if (playGame())
  {
    std::cout << "You win\n";
  }else
  {
    std::cout << "you lose\n";
  }

  return 0;
}
