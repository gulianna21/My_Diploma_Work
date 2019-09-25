#pragma once

#include<iostream>
#include <vector>
#include "Mutation.h"

class Selection : public Mutation
{
public:

  int GetCountPopulation()
  {
    return countPopulation;
  }

  std::vector<std::vector<int>> workingWithPopulations(std::vector<std::vector<int>> distances, std::vector<int> population, std::vector<std::vector<int>> populations);

  int mediumLengthPopulation(std::vector<std::vector<int>> distances, std::vector<std::vector<int> > populations);

private:
  int countPopulation;
};
