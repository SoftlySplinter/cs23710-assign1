/** 
 * @brief The source file for a company.
 * @file company.h
 * @author Alexander Brown
 *
 * Created 18 November 2010
 *
 * Modified 09 December 2010 - Changed to use NULL instead of 0.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../lib/shortest.h"

#include "company.h"
#include "delivery.h"
#include "misc.h"
#include "region.h"

void loadCompany(FILE *file, company *company) {
  char *filename;
  FILE *datafile;
  
  company->name = calloc(MAX_NAME_SIZE,sizeof(char));
  fgets(company->name,MAX_NAME_SIZE-1,file);
  company->name = strtok(company->name,"\n");
  
  filename = calloc(MAX_NAME_SIZE,sizeof(char));
  fscanf(file,"%s",filename);
  datafile = fopen(filename,"r");
  if(NULL == datafile) {
    printf("Invalid region file: %s\n",filename);
    return;
  }
  else {
    loadRegion(datafile, &(company->region));
  }
  
  fscanf(file,"%s",filename);
  datafile = fopen(filename,"r");
  if(NULL == datafile) {
    printf("Invalid roads file: %s\n",filename);
    return;
  }
  else { 
    loadRoads(datafile,company);
  }
  
  fscanf(file,"%s",filename);
  datafile = fopen(filename,"r"); 
  if(NULL == datafile) {
    printf("Invalid parks file %s\n",filename);
    return;
  }
  else {
    int i;
    company->numberOfParks = entryCount(datafile);
    company->parks = calloc(company->numberOfParks,sizeof(int));
    
    for(i=0;i<company->numberOfParks;i++)
    {
      fscanf(datafile,"%d",&(company->parks[i]));
    }
  }
  
  fscanf(file,"%s",filename);
  datafile = fopen(filename,"r");
  if(NULL == datafile) {
    printf("Invalid deliveries file %s\n", filename);
    return;
  }
  else {
    company->numberOfDeliveries = lineCount(datafile);
    company->deliveries = calloc(company->numberOfDeliveries, sizeof(delivery));
    loadDeliveries(datafile, company->deliveries, company->numberOfDeliveries);
  }
  
  fscanf(file,"%s", filename);
  datafile = fopen(filename, "r");
  if(0 == datafile) {
    printf("Invalid vans file %s\n", filename);
    return;
  }
  else {
    fscanf(datafile, "%f %f", &(company->runningCostEmpty), &(company->runningCostPerKg));
  }
  
  fclose(datafile);
  free(filename);
}

void loadRoads(FILE * file, company *company) {
  road *parent;
  road *cursor;
  
  company->roads = malloc(sizeof(road));
  
  cursor = company->roads;
  
  fscanf(file,"%d %d %d",&cursor->from,&cursor->to,&cursor->length);
  
  /* Seemingly infinite loop, but breaks when EOF is found */
  while(1) {
    parent = cursor;
    cursor = malloc(sizeof(road));
    if(fscanf(file,"%d %d %d", &cursor->from, &cursor->to, &cursor->length) != EOF){
      parent->next = cursor;
    }
    else {
      free(cursor);
      break;
    }
  }
}
