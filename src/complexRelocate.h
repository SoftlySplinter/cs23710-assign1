/** 
 * @brief The header file for the complex run routine.
 * @file
 * @author Alexander Brown
 *
 * Created 14 November 2010
 */

#include <stdio.h>

#include "company.h"

#ifndef _COMPLEX_RELOCATE
#define _COMPLEX_RELOCATE 

/**
 * @brief Runs the program using the cost of making deliveries.
 *
 * @param mainFile The input file from the user.
 */
void runComplex(FILE * mainFile);

/**
 * @brief Gets the cost from a particular location using the details of a particular company.
 *
 * @param location The reference number of the park @see region.locations
 * @param company The company to relocate.
 */
float getCostFromPark(int location, company company);

#endif
