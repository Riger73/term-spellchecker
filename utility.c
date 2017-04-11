#include "utility.h"
#include "list.h"
/**
 * @file utility.c contains implementations of helper functions and i/o functions
 * for the program
 **/

/**
 * clear the input buffer when the user has entered more data than allowed.
 * You should only call this when you have detected leftover input in the 
 * input buffer
 **/
static void read_rest_of_line(void)
{
	int ch;
	while(ch = getc(stdin), ch != '\n' && ch != EOF)
		;
	clearerr(stdin);
}

/**
 * @param checker the datastructure that holds all the data for the
 * system
 **/
BOOLEAN system_init(struct checker_system * checker)
{
	return FALSE;
}

/**
 * @param checker the datastructure that maintains all the information 
 * about the system
 * @param filename the filename to load the dictionary from
 **/
BOOLEAN load_data(struct checker_system* checker, const char * filename)
{
	return FALSE;
}

/**
 * @param checker the datastructure used to manage the system
 **/
void system_free(struct checker_system* checker)
{
}

