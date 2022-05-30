#ifndef orderOperation
#define orderOperation
#include "basic.h"
#include "myDS.h"

/***********************************************
* initOrder: create order queue and initialize *
************************************************/
struct orderQueue *initOrder(void);

/*******************************************
* isEmpty: check if current queue is empty *
*          Empty: return FALSE             *
*          Non empty: return TRUE          *
********************************************/
BOOL isEmpty(struct orderQueue *q);

/********************
* addOrder: Enqueue *
*********************/
BOOL addOrder(struct orderQueue *q, char CustomerName[], int orderId, int inventoryIds [], int inventoryQuantity [], int totalPrice, time_t orderDate);

/****************************************************************
* sortOrder: sort order by id or total price in ASC or DESC way *
*****************************************************************/
void sortOrder(struct orderQueue *q, int order, int order_by);

/*******************************************************
* searchOrder: search order by id and print order info *
********************************************************/
void searchOrder(struct orderQueue *q, int orderId);

/*************************************************************************
* completeOrder: delete queue of head for complete the most ealier order *
**************************************************************************/
BOOL completeOrder(struct orderQueue *q);

/***************************************************
* cancelOrder: delete queue by id for cancel order * 
****************************************************/
BOOL cancelOrder(struct orderQueue *q, int orderId);

/************************************************************************************************************
* checkReplenish: compare quantity between order and inventory, check whether to send a replenishment alert * 
*************************************************************************************************************/
void checkReplenish(struct orderQueue *q, int inventoryId);
#endif 
