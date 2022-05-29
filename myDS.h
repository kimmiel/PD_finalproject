#ifndef myDS_H
#define myDS_H
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
    struct Inventory *inv_head;
};

/****************************************
 * Order: use queue to implement *
 ****************************************/
struct Order {
    char CustomerName [MAX_CUSTOMER_NAME];
    int orderId;
    int inventoryIds [20];
    int inventoryQuantity [20];
    int totalPrice;
    time_t orderDate;
    struct Order *prev;
    struct Order *next;
};

#endif
