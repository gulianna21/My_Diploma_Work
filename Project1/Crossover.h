#pragma once

#include <vector>
#include "Set.h"

class Crossover : public Set
{
public:
  Crossover();

  std::vector<std::vector<int> > getPair(std::vector<std::vector<int>> waysCountry, int count1,int count2);

  std::vector<int> createNewChildForCyclic—rossover(std::vector<std::vector<int>> pair);

  template <class T, class X> bool Contains(T child, X index);

  std::vector<std::vector<int> > cyclic—rossover(std::vector<std::vector<int>> waysCountry);

  std::vector<std::vector<int> > change—rossover(std::vector<std::vector<int>> waysCountry);

  std::vector<int> createNewChildForChange—rossover(std::vector<std::vector<int>> pair, int point);

  std::vector<int> MBSmethod(std::vector<std::vector<int>> waysCountry, std::vector<std::vector<int>> pair);

  int getNearMin(std::vector<std::vector<int>> waysCountry, int point, std::vector<int> parents, std::vector<int> child);

  std::vector<std::vector<int> > mainMethod(std::vector<std::vector<int>> waysCountry, std::vector<std::vector<int>> population);

private:
  int crossCount;
};
