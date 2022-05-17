#include "basic.h"
#include "inventoryOperation.h"

struct category cat_list[MAX_CATEGORY];//the list of category

void initInv(void){
	int i;
	for(i = 0; i < MAX_CATEGORY; i++){
		//made the cat_list
		cat_list[i].type = i;
		cat_list[i].inventory_head = NULL;
	}
}

void addInv(char name[], double price, int quantity, int type){
	struct inventory *new_inv = malloc(sizeof(struct inventory));
	new_inv->id = id;
	new_inv->name = name;
	new_inv->price = price;
	new_inv->quantity = quantity;
	new_inv->next = NULL;

	if(cat_list[type] == NULL){//if the list is null
		cat_list[type].inventory_head = new_inv;
	}
	else{
		struct inventory *current = cat_list[type].inventory_head;
		
		while(current->next != NULL){//find the end of the list
			current = current->next;
		}

		current->next = new_inv;
	}
}

void traversaInv(){
	int i;
	for(i = 0; i < MAX_CATEGORY; i++){
		printf("type %d:\n", i);
		struct inventory *current = cat_list[i].inventory_head;
		printf("id\tname\tprice\tquantity\n");
		while(current != NULL){
			printf("%d\t%s\t%f\t%d\n", current->id, current->name, current->price, current->quantity);
			current = current->next;
		}
		
	}
}

void sortInv(int order, int order_by){
	if(order_by == 0){
		//descending
	}
	else if(order_by == 1){
		//ascending
	}
	else{
		fprintf(stderr, "Wrong order_by parameter, please input 0 or 1\n");
	}

}
