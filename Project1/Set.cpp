#pragma once
#include <iostream>

#include "Set.h"
#include <math.h>
#include <vector>

using namespace std;

Set::Set()
{
}

// ��������� ��������� ������������ �������
std::vector<int> Set::codir(int* Encoding, int NumberOf�ities)
{
  std::vector<int> s;
  // ���������� ��������� ������������
  for (int i = NumberOf�ities - 1; i >= 0; i--)
  {
    int j = rand() % (i + 1);

    int tmp = Encoding[j];
    Encoding[j] = Encoding[i];
    Encoding[i] = tmp;
    s.push_back(Encoding[i]);
    std::cout << Encoding[i] << " ";
  }
  std::cout << endl;
  return s;
}

//������������ ����������
std::vector<std::vector<int> > Set::formation(int* Encoding, int count)
{
  //vector<std::vector<int> > result;
  for (int i = 0; i < count; i++)
  {
    m_vector.push_back(codir(Encoding, 10));
  }
  return m_vector;
}

// ��������� ��������� ������� ���������� �� ������ ������ � �������
std::vector<std::vector<int> > Set::generatedWays(int count, int iterationCount)
{
  ways.assign(iterationCount, vector<int> (iterationCount));
  int rast;
  std::cout << endl;
  for (int k = 0; k < count; k++)
  {
    for (int i = 0; i < count; i++)
    {
      if (i == k)
      {
        ways[k][i] = 0;
      }
      else if (ways[k][i] == 0 && ways[i][k] == 0)
      {
        rast = rand() % 255 + 1;
        ways[i][k] = ways[k][i] = rast;
      }
      std::cout << ways[i][k] << " ";
    }
    std::cout << endl;
  }
  std::cout << endl;
  return ways;

}

// ����� ��������� ���������� ����� ����� ��������.
double Set::Rast(vector<vector<int> > rast,int indexTown1, int indexTown2)
{
  for (int i = 0; i < rast.size(); i++)
  {
   
  }
  rast[indexTown1][indexTown2];
  return 0.0;
}
