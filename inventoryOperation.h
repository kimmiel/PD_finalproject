#ifndef inventoryOperation
#define inventoryOperation
#include "basic.h"
#include "myDS.h"

 void initInv(void);//initialization
 void addInv(char name[], double prrice, int quantity, enum bookType type);//add produce
 void traversaInv();//printf each item
 void sortInv(int order, int order_by);//order(1:升序 0:降序) order_by(1:price 0:id)
 void deleteInv(int id);//delete produce
 void searchInvByID(int id);//search id and print the specific item
 void searchInvByName(char name[]);//search name and print the specific item
 int cmpDesById(const void *a, const void *b);//Compare for qsort
 int cmpAscById(const void *a, const void *b);//Compare for qsort
 int cmpDesByPrice(const void *a, const void *b);//Compare for qsort
 int cmpAscByPrice(const void *a, const void *b);//Compare for qsort
 void printList(struct inventory arr[]);//print out the id,name,price,quantity
 
#endif
