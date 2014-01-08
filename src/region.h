/** 
 * @brief The header file for regions.
 * @file
 * @author Alexander Brown
 *
 * Created 14 November 2010
 */

#include <stdio.h>

#ifndef MAX_NAME_SIZE
/**
 * The maximum size of any name string for a region or locations.
 */
#define MAX_NAME_SIZE 255
#endif

#ifndef _REGION
#define _REGION

/**
 * @brief The following structure defines a location.
 */
typedef struct
{
  /**
   * @brief The location code of the location defined by this structure.
   */
  int code;
  
  /**
   * @brief The name of this location.
   */
  char *name;
} location;

/**
 * @brief The following structure defines a region.
 */
typedef struct
{
  /**
   * @brief The name of this region
   */
  char *name;
  
  /**
   * @brief The number of locations held by this structure.
   */
  int numberOfLocations;
  
  /**
   * @brief The locations held by this structure.
   */
  location *locations;
} region;

/**
 * @brief Loads a region from a given file.
 * @param file The file to load from.
 * @param region The region to work with.
 */
void loadRegion(FILE * file, region * region);

/**
 * @brief Counts the number of locations in a location file (number of lines - 1).
 *
 * @param file The file to get number of lines of.
 *
 * @return The number of locations in a location file.
 */
int numberOfLocations(FILE * file);

#endif
