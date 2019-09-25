#pragma once

#include<iostream>
#include <vector>

using namespace std;

class Set
{
public:
  Set();
  Set(int NumberOf�ities)
  {
    this->NumberOf�ities = NumberOf�ities;
  };

  std::vector<int> codir(int* Encoding, int NumberOf�ities);

  std::vector<std::vector<int> > formation(int* Encoding, int count);

  std::vector<std::vector<int> > generatedWays(int count, int iterationCount);

  double Rast(vector<vector<int> > rast, int indexTown1, int indexTown2);

  std::vector<std::vector<int> > GetWays()
  {
    return ways;
  }

  //~Set();
private:
  // ���������� �������
  int NumberOf�ities;
  // ���� ���������
  int Encoding[10];

  std::vector<std::vector<int> > m_vector, ways;
};
