/** 
 * @brief The source file for a delivery.
 * @file
 * @author Alexander Brown
 *
 * Created 18 November 2010
 */

#include <stdio.h>
#include <stdlib.h>

#include "delivery.h"
#include "misc.h"

void loadDeliveries( FILE *file, delivery *deliveries, int noDeliveries) {
  int i;
  rewind(file);
  
  for(i=0;i<noDeliveries;i++) {
    fscanf(file,"%d %d %d %d",
      &(deliveries[i].retailer), 
      &(deliveries[i].location), 
      &(deliveries[i].deliveries), 
      &(deliveries[i].weight));
  }
}
