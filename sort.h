#ifndef sort
#define sort
#include "basic.h"
#include "myDS.h"

/**********************************************************
* use to sort the inventory，compar is a function pointer *
**********************************************************/
void _sort(struct inventory *head, int (*cmp) (const void *a, const void *b));

struct inventory *quicksort(struct inventory *head, struct inventory *tail, int (*cmp)(const void *a, const void *b));
struct inventory *find_tail(struct inventory *head);
struct inventory *partition(struct inventory *head, struct inventory *tail, struct inventory **new_head, struct inventory **new_tail, int (*cmp)(const void *a, const void *b));

#endif