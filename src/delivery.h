/** 
 * @brief The header file for a delivery.
 * @file
 * @author Alexander Brown
 *
 * Created 18 November 2010
 */

#ifndef _DELIVERY_
#define _DELIVERY_

#include <stdio.h>

/**
 * @brief Defines a delivery.
 */
typedef struct {
  /**
   * The code for the retailer.
   */
  int retailer;
  
  /**
   * The location of the retailer.
   *
   * @see location.code
   */
  int location;
  
  /**
   * The number of deliveries per week.
   */
  int deliveries;
  
  /**
   * The weight of the delivery.
   */
  int weight;
} delivery;

/**
 * @brief Loads all deliveries from a file.
 * @param file The file to load from.
 * @param deliveries The deliveries to load to.
 */
void loadDeliveries( FILE * file , delivery *deliveries , int noDeliveries);

#endif

