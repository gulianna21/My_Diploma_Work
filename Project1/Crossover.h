#pragma once

#include <vector>
#include "Set.h"

class Crossover : public Set
{
public:
  Crossover();

  std::vector<std::vector<int> > getPair(std::vector<std::vector<int>> waysCountry, int count1,int count2);

  std::vector<int> createNewChildForCyclic—rossover(std::vector<std::vector<int>> pair);

  template <class T, class X> bool NotHave(T child, X index);

  std::vector<std::vector<int> > cyclic—rossover(std::vector<std::vector<int>> waysCountry);

  std::vector<std::vector<int> > change—rossover(std::vector<std::vector<int>> waysCountry);

  std::vector<int> createNewChildForChange—rossover(std::vector<std::vector<int>> pair, int point);

private:
  int crossCount;
};
