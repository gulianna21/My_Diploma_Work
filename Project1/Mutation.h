#pragma once

#include <vector>
#include "Set.h"

class Mutation
{
public:
  enum Mode
  {
    Minimum,
    Maximum
  };

  enum Attempt
  {
    First,
    Second,
    Third
  };

  int GetCountMutation()
  {
    return countMutation;
  }

  // ������� ������� � �������� ���������� �� ���������.
  int findValueMutation(Mode d, std::vector<std::vector<int>> distances, std::vector<int> population);

  // �������� ���� ��������� �� ������
  std::vector<int> mutatedOnePopulation(std::vector<std::vector<int>> distances, std::vector<int> population, int numberMutations);

  // ��������� ����� ����� �� ������������ �������
  std::vector<std::vector<int> > returnMutation(std::vector<std::vector<int>> distances, std::vector<std::vector<int>> waysCountry, int countIteration);

  // �������� ���������� ����� ����� ��������.
  int GetDistance(std::vector<std::vector<int> > distances, int count1, int count2, int countIteration);

  // ����� ����� ���������
  int findLength(std::vector<std::vector<int>> distances, std::vector<int> population);

  //������������ ����� ���������
  std::vector<int> formationNewPopulation(std::vector<std::vector<int>> distances, std::vector<int> population, Attempt c);

  std::vector<int> massVertex(std::vector<std::vector<int>> distances, std::vector<int> population);

  int findPosition(int position, std::vector<int> population);

private:
  int countMutation;
};
