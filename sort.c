#include "sort.h"
#include "myDS.h"

void _sort(struct inventory *head, int (*cmp) (const void *a, const void *b)){
    head = quicksort(head, find_tail(head), cmp);
}

struct inventory *quicksort(struct inventory *head, struct inventory *tail, int (*cmp)(struct inventory *a, struct inventory *b)){
    if(head == tail){
        //nothing to sort
        return head;
    }

    struct inventory *new_head = NULL, *new_tail = NULL;
    struct inventory *pivot = partition(head, tail, &new_head, &new_tail, cmp);
    if(pivot != new_head){//pivot is not the first node
        //sort the left list
        struct inventory *temp = new_head;
        //let the last node of left list point to NULL
        while (temp->next != pivot)
            temp = temp->next;
        temp->next = NULL;

        new_head = quicksort(new_head, temp, cmp);

        //link the sorted list to the origin list
        temp = find_tail(new_head);
        temp->next = pivot;

    }
    if(pivot != new_tail){//pivot is not the last node
        //sort right list
        pivot->next = quicksort(pivot->next, new_tail, cmp);

    }

    return new_head;
}

struct inventory *find_tail(struct inventory *head){
    struct inventory *current = head;
    while(current != NULL && current->next != NULL){
        //check if the list is empty and current is the last node or not
        current = current->next;
    }

    return current;
}

struct inventory *partition(struct inventory *head, struct inventory *tail, struct inventory **new_head, struct inventory **new_tail, int (*cmp)(struct inventory *a, struct inventory *b)){
    struct inventory *pivot = head;//set the first node as pivot
    struct inventory *current = head;
    struct inventory *prev = NULL;

    while(current != NULL){

        if(cmp(current, pivot) == -1){
            //move the node to the left of pivot
            prev->next = current->next;
            current->next = head;
            head = current;
            current = prev;
        }
        else{
            //move tail，the node should be at the right of pivot
            tail = current;
        }

        
        prev = current;
        current = current->next;
    }

    (*new_head) = head;
    (*new_tail) = tail;

    return pivot;
}