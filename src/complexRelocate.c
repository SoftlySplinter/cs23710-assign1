/** 
 * @brief The source file for the complex run routine.
 * @file
 * @author Alexander Brown
 *
 * Created 14 November 2010
 *
 * Modified 09 December 2010 - Changed to use NULL instead of 0.
 */

#include <stdlib.h>
#include <stdio.h>

#include "../lib/shortest.h"

#include "company.h"
#include "complexRelocate.h"
#include "delivery.h"
#include "misc.h"
#include "region.h"

void runComplex(FILE *file) {
  company company;
  int i;
  float *costs;
  float lowestCost;
  int bestLocation;
  
  loadCompany(file, &company);
  
  printf("Company name: %s\n",company.name);
  
  costs = calloc(company.numberOfParks,sizeof(float));
  
  costs[0] = getCostFromPark(company.parks[0],company);
  lowestCost = costs[0];
  bestLocation = company.parks[0];
  
  for(i=1;i<company.numberOfParks;i++) {
    costs[i] = getCostFromPark(company.parks[i],company);
    
    if(costs[i] < lowestCost) {
      lowestCost = costs[i];
      bestLocation = company.parks[i];
    }
  }
  
  free(costs);
  /* Free up memory */
  for(i=0;i<company.region.numberOfLocations;i++)
    free(company.region.locations[i].name);
  free(company.region.locations);
  free(company.region.name);
  free(company.name);
  
  while(NULL != company.roads->next) {
    road *temp = company.roads->next;
	free(company.roads);
	company.roads = temp;
  }
  
  lowestCost /= 100; /* Divide by 100 to get pounds from pence */
  
  printf("Best location is %s (with a running cost of £%.2f).\n",
    company.region.locations[bestLocation].name, 
    lowestCost);
  
}

float getCostFromPark(int location, company company) {
  float cost = 0;
  int i;
  road *route;
  
  for(i=0;i<company.numberOfDeliveries;i++) {
    int currentCost = 0;
    
    route = shortest_route(location, 
      company.deliveries[i].location, 
      company.region.numberOfLocations, 
      company.roads);
    
    while(NULL != route) {
      currentCost += route->length;
      route = route->next;
    }
    
    currentCost *= company.deliveries[i].deliveries;
    cost += currentCost * (company.runningCostEmpty + 
      (company.runningCostPerKg * company.deliveries[i].weight));
    cost += currentCost * company.runningCostEmpty;
  }
  
  return cost;
}
