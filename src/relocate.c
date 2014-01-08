/** 
 * @brief The main class for the relocating program.
 * @file relocate.c
 * @author Alexander Brown
 *
 * Created 14 November 2010
 */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "complexRelocate.h"
#include "simpleRelocate.h"

/**
 * @brief The current version of the program.
 */
#define VERSION "1.0"

/**
 * @brief The path to the man page.
 */
#define HELP_FILE "man/relocate.txt"

#define SIMPLE_RELOCATE (1)
#define COMPLEX_RELOCATE (2)

/**
 * @brief Prints the man page when the option '-h' or '--help' is used.
 * @see VERSION
 */
void printHelp() {
  FILE *helpFile = fopen(HELP_FILE,"r");
  if(NULL==helpFile) {
    printf("Help not found\n");
  }
  else {
    int c;
    while((c=fgetc(helpFile))!=EOF) {
      printf("%c",c);
    }
    fclose(helpFile);
  }
}

/**
 * @brief Runs the relocate program
 * @param argc The number of arguments specified.
 * @param argv The arguments specified.
 * @return The typical C return type depending on the success or failure of the program.
 */
int main(int argc, char **argv) {
  if(argc < 2) {
    printf("relocate: missing file operand\nTry `relocate --help' for more information.\n");
  }
  else {
    FILE *file = NULL;
    int runningOption = COMPLEX_RELOCATE;
    
    int i;
    for(i=1;i<argc;i++) {      
      if(strcmp(argv[i], "-h")==0 || strcmp(argv[i], "--help")==0) {
	printHelp();
	return EXIT_SUCCESS;
      }
      else if(strcmp(argv[i], "-v")==0 || strcmp(argv[i], "--version")==0) {
	printf("Relocating Aberystwyth Dairy Company program by Alex Brown, Version %s\n\n",VERSION);
	return EXIT_SUCCESS;
      }
      else if(strcmp(argv[i], "-s")==0 || strcmp(argv[i], "--simple")==0) {
	runningOption = SIMPLE_RELOCATE;
      }
      else if(strcmp(argv[i], "-c")==0 || strcmp(argv[i], "--complex")==0) {
	runningOption = COMPLEX_RELOCATE;
      }
      else if(strncmp(argv[i], "-",1)!=0) { /* If there isn't an option - assume it's a file */
	file = fopen(argv[i],"r");
	if(0==file) {
	  printf("Unrecognised file\n");
	  return EXIT_FAILURE;
	}
      }
      else {
	printf("relocate: unrecognised option '%s'\nTry `relocate --help' for more information.\n",argv[i]);
	return EXIT_FAILURE;
      }
    }
    
    if(NULL != file) {
      if(SIMPLE_RELOCATE == runningOption)
	runSimple(file);
      else if(COMPLEX_RELOCATE == runningOption)
	runComplex(file);
    
      fclose(file);
    }
    else {
      printf("relocate: file not specified\nTry `relocate --help' for more information.\n");
      return EXIT_FAILURE;
    }
  }
  
  return EXIT_SUCCESS;
}
