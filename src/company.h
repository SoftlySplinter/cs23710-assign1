/** 
 * @brief The header file for a company.
 * @file company.h
 * @author Alexander Brown
 *
 * Created 14 November 2010
 */

#include "region.h"
#include "delivery.h"
#include "../lib/shortest.h"

#ifndef MAX_NAME_SIZE
/** The maximum size of any name string for a region or locations. */
#define MAX_NAME_SIZE 255
#endif

#ifndef _COMPANY
#define _COMPANY

/**
 * @brief Structure for a company
 */
typedef struct {
  /** The name of the company. */
  char *name;
  
  /** The region which this company is located in. */
  region region;
  
  /** The linked list of roads. */
  road *roads;
  
  /** The parks in the region. */
  int *parks;
  
  /** The number of parks in the region. */
  int numberOfParks;
  
  /** The deliveries of the company. */ 
  delivery *deliveries;
  
  /**
   * The number of deliveries.
   */
  int numberOfDeliveries;
  
  /**  The cost of running a van empty. */
  float runningCostEmpty;
  
  /** The extra cost per kilogram of running a van. */
  float runningCostPerKg;
} company;

/**
 * @brief Loads a company from it's relevant description file.
 *
 * @param file The company description file.
 * @param company The company to set up.
 */
void loadCompany(FILE * file, company * company);

/**
 * @brief Loads the roads of a company.
 * @param file The road file.
 * @param company The company to hold the roads in.
 */
void loadRoads(FILE * file, company *company);

#endif
