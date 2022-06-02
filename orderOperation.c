#include "orderOperation.h"

//initial order queue
struct orderQueue order_queue = {NULL,NULL};  

BOOL isEmpty(void)
{  
    return !(order_queue.head) ? true : false;
}


BOOL addOrder(char CustomerName[], int inventoryIds[], int inventoryQuantity[], int totalPrice, time_t orderDate)
{
    static int orderID = 0;

    struct order *order_new = malloc(sizeof(struct order));
    if (!order_new)
    {
        return false;
    }

    //initalize order_new
    strcpy(order_new->CustomerName , CustomerName);
    order_new->orderId = orderID++;
    for(int i = 0 ; i < 20 ; i++)
    {
        order_new->inventoryIds[i] = inventoryIds[i];
        order_new->inventoryQuantity[i] = inventoryQuantity[i];
    }
    order_new->totalPrice = totalPrice;
    order_new->orderDate = orderDate;
    order_new->prev = NULL;
    order_new->next = NULL;
    
    if (isEmpty()) 
    {
        order_queue.head = order_new;
        order_queue.tail = order_new;
        return true;
    }
    
    order_queue.tail->next = order_new;
    order_new->prev = order_queue.tail;
    order_queue.tail = order_new;
    
    return true;
}

//order(1:升序 0:降序) order_by(1:price 0:id)
void sortOrder(int order, int order_by)
{
    struct order *ptr;
    if(order_by == 0)
    {
        if(order == 0)
        {
            for(ptr = order_queue.tail ; ptr != NULL ; ptr = ptr->prev)
            {
                //how to print??
                
            }
        }
        else if(order == 1)
        {
            for(ptr = order_queue.head ; ptr != NULL ; ptr = ptr->next)
            {
                //how to print??
            }
        }
    }
    else if(order_by == 1)
    {
        if(order == 0)
        {

        }
        else if(order == 1)
        {

        }
    }
}