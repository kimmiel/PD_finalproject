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

    //declare order_new
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
    
    //queue is empty. enqueue order_new.
    if (isEmpty()) 
    {
        order_queue.head = order_new;
        order_queue.tail = order_new;
        return true;
    }
    
    //queue is not empty. enqueue order_new. 
    order_queue.tail->next = order_new;
    order_new->prev = order_queue.tail;
    order_queue.tail = order_new;
    
    return true;
}

//order(1:升序 s:降序) order_by(1:price 0:id)
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
BOOL isEmpty(struct orderQueue *q){
    return !(q->head)? TRUE:FALSE;
}

void searchOrder(struct orderQueue *q, int orderId){
    if(isEmpty(q)){
        printf("There is no order.\n");
        return;
    }
    else{
        struct order *cur = q;
        while (cur->next != NULL){
            if(cur->orderId == orderId){
                printf("Find order:%d!\n", cur->orderId);
                return;
            }
            else{
                cur = cur->next;
            }
        }
        printf("Order not exist\n");
    }
}

BOOL completeOrder(struct orderQueue *q){
    if(isEmpty(q)){
        printf("There is no order.\n");
        return FALSE;
    }
    else{
        struct order *toComplete = q->head;
        q->head = q->head->next;
        printf("Order:%d complete!\n", toComplete->orderId); //for debug
        free(toComplete);
        return TRUE;
    }
}

BOOL cancelOrder(struct orderQueue *q, int orderId){
    if(isEmpty(q)){
        printf("There is no order.\n");
        return FALSE;
    }
    else{
        struct order *cur = q;
        while (cur->next != NULL){
            if(cur->orderId == orderId){
                struct order *toCancel = cur;
                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;
                printf("Order:%d canceled!\n", toCancel->orderId); //for debug
                free(toCancel);
                return TRUE;
            }
            else{
                cur = cur->next;
            }
        }
        printf("Order not exist\n");
        return FALSE;
    }
}
