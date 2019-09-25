#pragma once

#include <iostream>

#include "Mutation.h"
#include <math.h>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> Mutation::returnMutation(std::vector<std::vector<int>> distances, std::vector<std::vector<int>> waysCountry, int countIteration)
{
  for (int i = 0; i < waysCountry.size(); i++)
  {
    if ((rand() % 101 + 1) % 2 == 0)
    {
      cout << "Mutation number: "<<i<<" "<<endl;
      waysCountry[i] = mutatedOnePopulation(distances, waysCountry[i], countIteration);
    }
    else
    {
      waysCountry[i] = waysCountry[i];
      cout << "NO Mutation number: " << i << " " << endl;
      for (int i = 0; i < 1; i++)
      {
        for (int j = 0; j < countIteration; j++)
        {
          cout << waysCountry[i][j]<<" ";
        }
        cout << endl;
      }
    }
  }
  return waysCountry;
}
//fixed and work
int Mutation::findValueMutation(Mode sign, std::vector<std::vector<int>> distances, std::vector<int> population)
{
  int intermediate, dist = 0, size = population.size();
  if (sign == Minimum)
  {
    intermediate = 256;
    // ищем минимум
    for (int i = 0; i < size; i++)
    {
      dist = GetDistance(distances, population[i% size], population[(i + 1)% size], size);
      intermediate = std::min(intermediate, dist);
    }
  }
  else
  {
    intermediate = 0;
    // ищем максимум
    for (int i = 0; i < size; i++)
    {
      dist = GetDistance(distances, population[i% size], population[(i + 1) % size], size);
      intermediate = std::max(intermediate, dist);
    }
  }
  return intermediate;
}

// main method
std::vector<int> Mutation::mutatedOnePopulation(std::vector<std::vector<int>> distances, std::vector<int> population, int numberMutations)
{
  int lengthNewPopulation = 0, countDepth = 0;
// длина текущей популяции
  int lengthPopulation = findLength(distances, population);

  while(numberMutations)
  {
    std::vector<int> populationNew = formationNewPopulation(distances, population, First);
    lengthNewPopulation = findLength(distances, populationNew);

    if (lengthNewPopulation < lengthPopulation)
    {
      population = populationNew;
      break;
    }
    else
    {
      populationNew = formationNewPopulation(distances, population, Second);
      lengthNewPopulation = findLength(distances, populationNew);
      if (lengthNewPopulation < lengthPopulation)
      {
        population = populationNew;
        break;
      }
      else 
      {
        populationNew = formationNewPopulation(distances, population, Third);
        lengthNewPopulation = findLength(distances, populationNew);
        if (lengthNewPopulation < lengthPopulation)
        {
          population = populationNew;
          break;
        }
        else break;
      }
    }
    countDepth += 1;
    numberMutations--;
  }
  for(int i=0;i<population.size();i++)
    cout << population[i]<<" ";
  cout <<"|||||  Old length: "<< lengthPopulation<<" |||||  New Length: "<<lengthNewPopulation<< endl;
  return population;
}

//fixed  and worked all
int Mutation::GetDistance(std::vector<std::vector<int>> distances, int count1, int count2, int countIteration)
{
  int result = distances[count1 - 1][count2 - 1];
  return result;
}

// fixed and all worked.
int Mutation::findLength(std::vector<std::vector<int>> distances, std::vector<int> population)
{
  int Q = 0;
  int size = population.size();
  for (int i = 1; i <= population.size(); i++)
  {
    int q1 = population[(i-1) % size];
    int q2 = population[i% size];
    Q += distances[q1-1][q2 - 1];
  }
  return Q;
}

std::vector<int> Mutation::formationNewPopulation(std::vector<std::vector<int>> distances, std::vector<int> population, Attempt option)
{
  int maxCiti1, maxCiti2, minCiti1, minCiti2;

  int max = findValueMutation(Maximum, distances, population);
  int min = findValueMutation(Minimum, distances, population);

  std::vector<int> mass = massVertex(distances, population);

  if (option == First)
  {
    for (int i = 0; i < 2; i++)
    {
      int temp = findPosition(mass[i], population);
      int temp1 = findPosition(mass[i+2], population);
      population[temp] = mass[i+2];
      population[temp1] = mass[i];
    }
  }

    if (option == Second)
    {
      for (int i = 0; i < 1; i++)
      {
        int temp = findPosition(mass[i], population);
        int temp1 = findPosition(mass[i + 2], population);
        population[temp] = mass[i + 2];
        population[temp1] = mass[i];
      }
    }

    if (option == Third)
    {
      for (int i = 1; i < 2; i++)
      {
        int temp = findPosition(mass[i], population);
        int temp1 = findPosition(mass[i + 2], population);
        population[temp] = mass[i + 2];
        population[temp1] = mass[i];
      }
    }

  return population;
}
 //fixed but perepolnenie memory
std::vector<int> Mutation::massVertex(std::vector<std::vector<int>> distances, std::vector<int> population)
{
  std::vector<int> mass;
  int intermediate = 256,dist,size = population.size();
  int maxCiti1 = 0, maxCiti2 = 0, minCiti1 = 0, minCiti2 = 0;

  for (int i = 0; i < size; i++)
  {
    dist = GetDistance(distances, population[i% size], population[(i + 1) % size], size);
    if (dist < intermediate)
    {
      intermediate = std::min(intermediate, dist);
      minCiti1 = population[i% size];
      minCiti2 = population[(i + 1) % size];
    }
  }

  mass.push_back(minCiti1);
  mass.push_back(minCiti2);

  intermediate = 0;
  for (int i = 0; i < size; i++)
  {
    dist = GetDistance(distances, population[i% size], population[(i + 1) % size], size);
    if (dist > intermediate)
    {
      intermediate = std::max(intermediate, dist);
      maxCiti1 = population[i% size];
      maxCiti2 = population[(i + 1) % size];
    }
  }

  mass.push_back(maxCiti1);
  mass.push_back(maxCiti2);

  return mass;
}

int Mutation::findPosition(int position, std::vector<int> population)
{
  int number = 0;
  for (int i = 0; i < population.size(); i++)
  {
    if (position == population[i])
      number = i;
  }
  return number;
}
