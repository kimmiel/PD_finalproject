#ifndef myDS_H
#define myDS_H
typedef int BOOL;
#include <time.h>

enum bookType {EDU , FIN, NOVEL};

struct inventory {
    int inventoryId;
    char inventoryName [MAX_BOOK_NAME];
    double price;
    int quantity;
    struct inventory *next;
};

struct category {
    enum bookType type;
    struct inventory *inv_head;
};

/********************************
* Order: use queue to implement *
*********************************/
struct order {
    char CustomerName [MAX_CUSTOMER_NAME];
    int orderId;
    int inventoryIds[20];
    int inventoryQuantity[20];
    int totalPrice;
    time_t orderDate;
    struct order *prev;
    struct order *next;
};

struct orderQueue {
    struct order *head;
    struct order *tail;
};

#endif
