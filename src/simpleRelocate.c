/** 
 * @brief The source file for the simple run routine.
 * @file
 * @author Alexander Brown
 *
 * Created 14 November 2010
 *
 * Modified 09 December 2010 - Changed to use NULL instead of 0.
 */

#include <stdlib.h>
#include <stdio.h>

#include "simpleRelocate.h"
#include "company.h"
#include "region.h"
#include "delivery.h"
#include "../lib/shortest.h"

void runSimple(FILE *file) {
  company company;
  int i;
  int *distances;
  int shortestPath;
  int bestLocation;
  
  loadCompany(file, &company);
  
  printf("Company name: %s\n",company.name);
  
  distances = calloc(company.numberOfParks,sizeof(int));
  
  distances[0] = getDistanceFromPark(company.parks[0],company);
  shortestPath = distances[0];
  bestLocation = company.parks[0];
  
  for(i=1;i<company.numberOfParks;i++) {
    distances[i] = getDistanceFromPark(company.parks[i],company);
    if(distances[i] < shortestPath) {
      shortestPath = distances[i];
      bestLocation = company.parks[i];
    }
  }
  
  free(distances);
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
  
  printf("Best location is %s (with a total distance of %d miles).\n",
    company.region.locations[bestLocation].name, 
    shortestPath);
}

int getDistanceFromPark(int location, company company) {
  int distance = 0;
  int i;
  road *route;
  
  for(i=0;i<company.numberOfDeliveries;i++) {
    int currentDistance = 0;
    
    route = shortest_route(location, 
      company.deliveries[i].location, 
      company.region.numberOfLocations, 
      company.roads);
    
    while(NULL != route) {
      currentDistance += route->length;
      route = route->next;
    }
    
    currentDistance *= company.deliveries[i].deliveries;
    distance += currentDistance;
  }
  
  return distance*2; /* Times by two for there and back */
}
