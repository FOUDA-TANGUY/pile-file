#include <stdlib.h>
#include <element.h>

element* new_element(void)
{
	return (element*)malloc(sizeof(element));
}

void free_element(element* elmt)
{
	free(elmt);
}