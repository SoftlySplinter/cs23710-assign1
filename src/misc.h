/** 
 * @brief The header file for miscallanous functions.
 * @file 
 * @author Alexander Brown
 *
 * Created 18 November 2010
 */

#include <stdio.h>

/**
 * @brief Counts the number of lines in a file.
 *
 * @param file The file to count lines of.
 */
int lineCount(FILE * file);

/**
 * @brief Counts the number of entries in a file.
 *
 * @note Counts the number of spaces in a file and adds one.
 *
 * @param file The file to count entries in.
 */
int entryCount(FILE * file);
