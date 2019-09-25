#pragma once

#include <iostream>

#include "Selection.h"
#include "Mutation.h"

std::vector<std::vector<int>> Selection::workingWithPopulations(std::vector<std::vector<int>> distances, std::vector<int> population, std::vector<std::vector<int>> populations)
{
  std::vector<std::vector<int>> newPopul;
  int l = findLength(distances, population);
  int medium = mediumLengthPopulation(distances, populations);
  cout << "length : "<<l <<" Medium length all: "<< medium<<endl;
  if (l < medium)
  {
    newPopul.push_back(population);
  }
  return newPopul;
}

int Selection::mediumLengthPopulation(std::vector<std::vector<int>> distances, std::vector<std::vector<int>> populations)
{
  int temp = 0;
  int size = populations.size();
  for (int j = 0; j < size; j++)
  {
    int Q = 0;
    for (int i = 1; i <= size; i++)
    {
      int q1 = populations[j][(i - 1) % size];
      int q2 = populations[j][i% size];
      Q += distances[q1 - 1][q2 - 1];
    }
    temp += Q;
    //cout << "Q: "<<Q<<" temp : " << temp << endl;
  }
  cout << endl;
  return (int)(temp / size);
}
