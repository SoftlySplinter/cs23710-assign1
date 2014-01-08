/** 
 * @brief The source file for miscallanous functions.
 * @file 
 * @author Alexander Brown
 *
 * Created 18 November 2010
 */

#include <stdio.h>
#include "misc.h"

int lineCount(FILE * file) {
  int lines = 0;
  int c;
  
  while((c=fgetc(file))!=EOF) {
    if(c=='\n')
      lines++;
  }
  
  rewind(file);
  return lines;
}

int entryCount(FILE *file) {
  int entries = 0;
  int c;
  
  while((c=fgetc(file))!=EOF)
    if(' ' == c)
      entries++;
    
  rewind(file);
  return entries+1; /* Add one for the last entry */
}
