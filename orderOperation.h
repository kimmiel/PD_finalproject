#ifndef orderOperation
#define orderOperation
#include "basic.h"
#include "myDS.h"

 void initOrder(void);
 void addOrder(char name[], double price, int quantity, enum bookType type);
 void sortOrder(int order, int order_by);
 void deleteOrder(int orderId);
 void searchOrder(int orderId);
 
#endif 
