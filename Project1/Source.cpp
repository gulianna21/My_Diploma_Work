#include <iostream>

#include "Set.h"
#include "Mutation.h"
#include "Crossover.h"
#include "Selection.h"
#include <algorithm>

int main()
{
  int countIteration = 10;
  Set qwe{ countIteration };
  int a[] = { 1,2,3,4,5,6,7,8,9,10 };
  std::vector<std::vector<int> > newPopulation = qwe.formation(a, countIteration);
  std::vector<std::vector<int> > newDistance = qwe.generatedWays(countIteration, countIteration);
  int countPopulation = 0;

  while (countIteration - 5) 
  {
    /*if (countPopulation)
    {*/
      cout << endl;
      Crossover cross;
      cout << "Crossover!" << endl;
      //newPopulation = cross.cyclicÑrossover(newPopulation);
      newPopulation = cross.changeÑrossover(newPopulation);
    //}

    cout << endl;
    Mutation mutation;
    cout << "Mutation!" << endl;
    //std::vector<std::vector<int> > newPopulationAfterMutation = mutation.returnMutation(newDistance, newPopulation, countIteration);
    //std::cout<<newPopulationAfterMutation.size();
    std::vector<std::vector<int> > newPopulationAfterMutation;
    std::vector<int> temp;
    for (int i = 0; i < newPopulation.size(); i++)
    {
      cout << "N:" << i+1 << " |||| ";
      temp = mutation.mutatedOnePopulation(newDistance, newPopulation[i], newPopulation.size());
      newPopulationAfterMutation.push_back(temp);
    }

    cout << endl;
    Selection select;
    cout << "Selection!" << endl;
    newPopulation = select.workingWithPopulations(newDistance, newPopulationAfterMutation);

    cout << "END!" << endl;
    cout << "countPopulation:  " << countPopulation <<endl;
    if (newPopulation.size() == 0)
      break;
    countIteration--;
   /* if ((countIteration-5) <= 0)
    {
      // âûáîðêà ìèíèìàëüíîãî ïóòè èç ïîëó÷èâøåéñÿ ïîïóëÿöèè.
      Mutation a;
      int mins=256,c;
      for (int i = 0; i < newPopulation.size(); i++)
      {
        c = a.findLength(newDistance, newPopulation[i]);
        mins = min(mins, c);
      }
      cout << " Min: " << mins << endl;
    }*/
    countPopulation++;
  }
  cin.get();
  cin.get();
  return 0;
}