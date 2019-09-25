#pragma once

#include <vector>
#include "Set.h"

class Crossover : public Set
{
public:
  Crossover();

  std::vector<std::vector<int> > getPair(std::vector<std::vector<int>> waysCountry, int count);

  //std::vector<std::vector<int> > createNewPopulation(std::vector<std::vector<int>> waysCountry, int populationSize);

private:
  int crossCount;
};
