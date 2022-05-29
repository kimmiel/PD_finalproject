#ifndef sort
#define sort
#include "basic.h"
#include "myDS.h"

/**********************************************************
* use to sort the inventory，compar is a function pointer *
**********************************************************/
void _sort(struct inventory *head, int (*cmp) (const void *a, const void *b));

#endif