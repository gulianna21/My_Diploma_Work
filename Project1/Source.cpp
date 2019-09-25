#include <iostream>

#include "Set.h"
#include "Mutation.h"
#include "Crossover.h"
#include "Selection.h"

int main()
{
  int countIteration = 10;
  Set qwe{ countIteration };
  int a[] = { 1,2,3,4,5,6,7,8,9,10 };
  std::vector<std::vector<int> > newPopulation = qwe.formation(a, countIteration);
  std::vector<std::vector<int> > newDistance = qwe.generatedWays(countIteration, countIteration);

  /*Crossover cross;
  cross.getPair(newPopulation, countIteration);*/
  while (countIteration - 5) 
  {
    Mutation mutation;
    //std::vector<std::vector<int> > newPopulationAfterMutation = mutation.returnMutation(newDistance, newPopulation, countIteration);
    //std::cout<<newPopulationAfterMutation.size();
    std::vector<std::vector<int> > newPopulationAfterMutation;
    std::vector<int> temp;
    for (int i = 0; i < newPopulation.size(); i++)
    {
      temp = mutation.mutatedOnePopulation(newDistance, newPopulation[i], newPopulation.size());
      newPopulationAfterMutation.push_back(temp);
    }

    Selection select;
    for (int i = 0; i < newPopulation.size(); i++)
    {
      newPopulation = select.workingWithPopulations(newDistance, newPopulationAfterMutation[i], newPopulationAfterMutation);
    }
    if (newPopulation.size() == 0)
      break;
    cout << "END!"<<endl;
    countIteration--;
  }
  cin.get();
  cin.get();
  return 0;
}