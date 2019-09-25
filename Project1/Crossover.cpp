#pragma once

#include <iostream>

#include <math.h>
#include <vector>

#include "Crossover.h"

Crossover::Crossover()
{
}

std::vector<std::vector<int>> Crossover::getPair(std::vector<std::vector<int>> waysCountry, int count)
{
  std::vector<std::vector<int>> result;
  int size = waysCountry.size();

  for (int i = size -1; i > size -3; i--)
  {
    result.push_back(waysCountry[i]);
    waysCountry.pop_back();
  }
  return result;
}

/*std::vector<std::vector<int>> Crossover::createNewPopulation(std::vector<std::vector<int>> waysCountry, int populationSize)
{
  for (int i = 0; i < populationSize; i++)
  {

  }
  return std::vector<std::vector<int>>();
}*/
