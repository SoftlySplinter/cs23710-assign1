/** 
 * @brief The source file for regions and their operators.
 * @file 
 * @author Alexander Brown
 *
 * Created 14 November 2010
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "misc.h"
#include "region.h"

void loadRegion(FILE * file, region *region) {
  int noLocations = numberOfLocations(file);
  int i;
  
  region->name = calloc(MAX_NAME_SIZE, sizeof(char));
  region->numberOfLocations = noLocations;
  fgets(region->name,MAX_NAME_SIZE,file);
  region->name = strtok(region->name,"\n");
  
  region->locations = calloc(noLocations,sizeof(location));
  
  for(i=0;i<noLocations;i++) {
    region->locations[i].name = calloc(MAX_NAME_SIZE, sizeof(char));
    fscanf(file,"%d ",&(region->locations[i].code));
    fgets(region->locations[i].name,MAX_NAME_SIZE-1,file);
    
    region->locations[i].name = strtok(region->locations[i].name,"\n");
  }
}


int numberOfLocations(FILE * file) {
  return lineCount(file)-1;
}
