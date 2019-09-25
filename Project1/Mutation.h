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

  // находим минимум и максимум расстояния из популяции.
  int findValueMutation(Mode d, std::vector<std::vector<int>> distances, std::vector<int> population);

  // Мутируем одну популяцию из набора
  std::vector<int> mutatedOnePopulation(std::vector<std::vector<int>> distances, std::vector<int> population, int numberMutations);

  // Формируем новый набор из мутировавших наборов
  std::vector<std::vector<int> > returnMutation(std::vector<std::vector<int>> distances, std::vector<std::vector<int>> waysCountry, int countIteration);

  // получаем расстояние между двумя городами.
  int GetDistance(std::vector<std::vector<int> > distances, int count1, int count2, int countIteration);

  // найти длину популяции
  int findLength(std::vector<std::vector<int>> distances, std::vector<int> population);

  //формирование новой популяции
  std::vector<int> formationNewPopulation(std::vector<std::vector<int>> distances, std::vector<int> population, Attempt c);

  std::vector<int> massVertex(std::vector<std::vector<int>> distances, std::vector<int> population);

  int findPosition(int position, std::vector<int> population);

private:
  int countMutation;
};
