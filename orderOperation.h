#ifndef orderOperation
#define orderOperation
#include "basic.h"
 void initOrder(void);
 void addOrder(char name[], double price, int quantity, enum btype type);
 void sortOrder(int order, int order_by);
 void deleteOrder(int orderId);
 void searchOrder(int orderId);
 
#endif 
