#pragma once

#include <iostream>

#include <math.h>
#include <vector>

#include "Crossover.h"

Crossover::Crossover()
{
  Crossover::crossCount = 0;
}

template <class T, class X>
bool Crossover::NotHave(T child, X index)
{
  for (int i = 0; i < child.size(); i++)
  {
    if (index == child[i])
    {
      return false;
    }
  }
  return true;
}

std::vector<std::vector<int>> Crossover::getPair(std::vector<std::vector<int>> waysCountry, int p1, int p2)
{
  std::vector<std::vector<int>> result;

  result.push_back(waysCountry[p1]);
  result.push_back(waysCountry[p2]);

  return result;
}

std::vector<int> Crossover::createNewChild(std::vector<std::vector<int>> pair)
{
  std::vector<int> child;
  for (int i = 0; i < pair[0].size(); i++)
  {
    if (NotHave(child, pair[0][i]))
    {
      child.push_back(pair[0][i]);
    }
    if (NotHave(child, pair[1][pair[0].size() - 1 - i]))
    {
      child.push_back(pair[1][pair[0].size() - 1 - i]);
    }
    if (child.size() == pair[0].size())
    {
      return child;
    }
  }
}

std::vector<std::vector<int>> Crossover::createNewPopulationChild(std::vector<std::vector<int>> waysCountry)
{
  std::vector<std::vector<int> > childs;
  int size = waysCountry.size();
  for (int i = 0; i < size; i++)
  {
    std::vector<std::vector<int>> pair1 = getPair(waysCountry, i % size, (i + 1) % size);
    std::vector<int> aChild = createNewChild(pair1);
    if (NotHave(childs, aChild))
      childs.push_back(aChild);

    std::vector<std::vector<int>> pair2 = getPair(waysCountry, (i + 1) % size, i % size);
    aChild = createNewChild(pair2);
    if (NotHave(childs, aChild))
      childs.push_back(aChild);
  }
  return childs;
}
