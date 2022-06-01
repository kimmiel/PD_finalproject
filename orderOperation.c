#include "orderOperation.h"

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
