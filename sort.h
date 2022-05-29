#ifndef sort
#define sort
#include "basic.h"
#include "myDS.h"

/**********************************************************
* use to sort the inventory，compar is a function pointer *
**********************************************************/
void sort(struct inventory *head, int (*cmp)(struct inventory *a, struct inventory *b));

#endif