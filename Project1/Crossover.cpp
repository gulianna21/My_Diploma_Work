#pragma once

#include <iostream>

#include <math.h>
#include <vector>

#include "Crossover.h"
#include <algorithm>

Crossover::Crossover()
{
  Crossover::crossCount = 0;
}

template <class T, class X>
bool Crossover::Contains(T child, X index)
{
  for (int i = 0; i < child.size(); i++)
  {
    if (index == child[i])
    {
      return true;
    }
  }
  return false;
}

std::vector<std::vector<int>> Crossover::getPair(std::vector<std::vector<int>> waysCountry, int p1, int p2)
{
  std::vector<std::vector<int>> result;

  result.push_back(waysCountry[p1]);
  result.push_back(waysCountry[p2]);

  return result;
}

std::vector<int> Crossover::createNewChildForCyclic—rossover(std::vector<std::vector<int>> pair)
{
  std::vector<int> child;
  for (int i = 0; i < pair[0].size(); i++)
  {
    if (!Contains(child, pair[0][i]))
    {
      child.push_back(pair[0][i]);
    }
    if (!Contains(child, pair[1][pair[0].size() - 1 - i]))
    {
      child.push_back(pair[1][pair[0].size() - 1 - i]);
    }
    if (child.size() == pair[0].size())
    {
      return child;
    }
  }
}

std::vector<std::vector<int>> Crossover::cyclic—rossover(std::vector<std::vector<int>> waysCountry)
{
  std::vector<std::vector<int> > childs;
  int size = waysCountry.size();
  for (int i = 0; i < size; i++)
  {
    std::vector<std::vector<int>> pair1 = getPair(waysCountry, i % size, (i + 1) % size);
    std::vector<int> aChild = createNewChildForCyclic—rossover(pair1);
    if (!Contains(childs, aChild))
      childs.push_back(aChild);

    std::vector<std::vector<int>> pair2 = getPair(waysCountry, (i + 1) % size, i % size);
    aChild = createNewChildForCyclic—rossover(pair2);
    if (!Contains(childs, aChild))
      childs.push_back(aChild);
  }
  return childs;
}

std::vector<std::vector<int>> Crossover::change—rossover(std::vector<std::vector<int>> waysCountry)
{
  std::vector<std::vector<int> > childs;
  int rand = 5;
  for (int i = 0; i < waysCountry.size(); i++)
  {
    std::vector<std::vector<int>> pair1 = getPair(waysCountry, i % waysCountry.size(), (i + 1) % waysCountry.size());
    std::vector<int> aChild = createNewChildForChange—rossover(pair1,rand); 
    childs.push_back(aChild);

    std::vector<std::vector<int>> pair2 = getPair(waysCountry, (i + 1) % waysCountry.size(), i % waysCountry.size());
    aChild = createNewChildForChange—rossover(pair2,rand);
    childs.push_back(aChild);
  }
  return childs;
}

std::vector<int> Crossover::createNewChildForChange—rossover(std::vector<std::vector<int>> pair, int point)
{
  std::vector<int> child;
  for (int i = 0; i < point; i++)
  {
    child.push_back(pair[0][i]);
  }
  for (int j = point; j < pair[0].size(); j++)
  {
    if (!Contains(child, pair[1][j]))
    {
      child.push_back(pair[1][j]);
    }
    else
    {
      child.push_back(pair[0][j]);
    }
  }

  return child;
}

std::vector<int> Crossover::MBSmethod(std::vector<std::vector<int>> waysCountry, std::vector<std::vector<int>> pair)
{
  std::vector<int> child;
  int point2;
  int point1 = rand() % (pair[0].size() - 3) + 1;
  if (point1 == pair[0].size() - 2)
  {
    point2 = pair[0].size() - 1;
  }
  else
  {
    point2 = point1 + rand() % (pair[0].size() - point1 - 2) + 1;
  }

  for (int i = 0; i < point1; i++)
  {
    child.push_back(pair[0][i]);
  }

  while (point1 != point2)
  {
    int town = getNearMin(waysCountry, point1, pair[0], child);

    if (!Contains(child, town))
    {
      child.push_back(town);
    }

    pair[0].erase(pair[0].begin() + town);

    point1++;
  }
  return child;
}

int Crossover::getNearMin(std::vector<std::vector<int>> waysCountry, int point1, std::vector<int> parents, std::vector<int> child)
{
  if (child.size() == parents.size() - 2)
  {
    return parents[parents.size() - 1];
  }
  int a = parents[point1];
  /*bool pointStop = true;
  while (pointStop)
  {
    if (!Contains(child, parents[point1 + 1]))
    {
      int b = parents[point1 + 1];
    }
    else
    {
      point
    }*/
    int minimum = waysCountry[parents[point1] - 1][parents[point1 + 1] - 1];
    int minVertex = parents[point1 + 1];
    for (int i = point1; i < parents.size() - 1; i++)
    {
      int c = parents[point1];
      int d = parents[i + 1];
      if (minimum > waysCountry[parents[point1] - 1][parents[i + 1] - 1])
      {
        minimum = waysCountry[parents[point1] - 1][parents[i + 1] - 1];
        minVertex = parents[i + 1];
      }
    }
  return 1;
}

std::vector<std::vector<int>> Crossover::mainMethod(std::vector<std::vector<int>> waysCountry, std::vector<std::vector<int>> population)
{
  std::vector<std::vector<int> > result;
  for (int j = 0; j < population.size() - 2; j++)
  {
    std::vector<std::vector<int> > pro;
    for (int i = j; i < 2; i++)
    {
      pro.push_back(population[i]);
    }
    result.push_back(MBSmethod(waysCountry, pro));
    j++;
  }
  return result;
}

