#pragma once

#include<iostream>
#include <vector>

using namespace std;

class Set
{
public:
  Set();
  Set(int NumberOfÑities)
  {
    this->NumberOfÑities = NumberOfÑities;
  };

  std::vector<int> codir(int* Encoding, int NumberOfÑities);

  std::vector<std::vector<int> > formation(int* Encoding, int count);

  std::vector<std::vector<int> > generatedWays(int count, int iterationCount);

  double Rast(vector<vector<int> > rast, int indexTown1, int indexTown2);

  std::vector<std::vector<int> > GetWays()
  {
    return ways;
  }

  //~Set();
private:
  // êîëè÷åñòâî ãîğîäîâ
  int NumberOfÑities;
  // îäíà êîäèğîâêà
  int Encoding[10];

  std::vector<std::vector<int> > m_vector, ways;
};
