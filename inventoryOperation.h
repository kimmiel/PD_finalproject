#ifndef inventoryOperation
#define inventoryOperation
#include "basic.h"

 void initInv(void);
 void addInv(char name[], double prrice, int quantity, enum btype type);
 void traversaInv();
 void sortInv(int order, int order_by);//order(1:升序 0:降序) order_by(1:price 0:id)
 void deleteInv(int id);
 void searchInvByID(int id);
 void searchInvByName(char name[]);
 int cmpDesById(const void *a, const void *b);
 int cmpAscById(const void *a, const void *b);
 int cmpDesByPrice(const void *a, const void *b);
 int cmpAscByPrice(const void *a, const void *b);
 void printList(struct inventory arr[]);
 
#endif
