#include "basic.h"
#include "inventoryOperation.h"

struct category cat_list[MAX_CATEGORY];//the list of category
int type1_len;//type1 inventory list length
int type2_len;//type2 inventory list length
int type3_len;//type3 inventory list length

void initInv(void){
	int i;
	for(i = 0; i < MAX_CATEGORY; i++){
		//made the cat_list
		cat_list[i].type = i;
		cat_list[i].inv_head = NULL;
	}

	type1_len = 0;
	type2_len = 0;
	type3_len = 0;
}

void addInv(char name[], double price, int quantity, enum btype type){
	//id for each inventory
	static int IDs[] = {100, 200, 300};

	//new inventory
	struct inventory *new_inv = malloc(sizeof(struct inventory));
	new_inv->id = IDs[type];
	new_inv->name = name;
	new_inv->price = price;
	new_inv->quantity = quantity;
	new_inv->next = NULL;

	if(cat_list[type] == NULL){//if the list is null
		cat_list[type].inv_head = new_inv;
	}
	else{
		struct inventory *current = cat_list[type].inv_head;
		
		while(current->next != NULL){//find the end of the list
			current = current->next;
		}

		current->next = new_inv;
	}

	IDs[type]++;//increase id

	//increase list length
	if(type == EDU){
		type1_len++;
	}
	else if(type == FIN){
		type2_len++;
	}
	else if(type == NOVEL){
		type3_len++;
	}

}

void traversaInv(){
	int i;
	for(i = 0; i < MAX_CATEGORY; i++){
		printf("type %d:\n", i);//print type
		struct inventory *current = cat_list[i].inv_head;
		printf("id\tname\tprice\tquantity\n");//print title
		while(current != NULL){
			//printf each item
			printf("%d\t%s\t%f\t%d\n", current->id, current->name, current->price, current->quantity);
			current = current->next;
		}
		
	}
}

void sortInv(int order, int order_by){
	int i = 0;
	
	//invnetory array
	struct inventory type1[type1_len];
	struct inventory type2[type2_len];
	struct inventory type3[type3_len];

	struct inventory type1_cur = cat_list[EDU].inv_head;
	struct inventory type2_cur = cat_list[FIN].inv_head;
	struct inventory type3_cur = cat_list[NOVEL].inv_head;
	
	//put inventory to array to use qsort
	for(i = 0; i < type1_len; i++){
		type1[i] = type1_cur;
		type1_cur = type1_cur -> next;
	}
	for(i = 0; i < type2_len; i++){
		type2[i] = type2_cur;
		type2_cur = type2_cur -> next;
	}
	for(i = 0 i < type3_len; i++){
		type3[i] = type3_cur;
		type3_cur = type3_cur -> next;
	}

	if(order == 0){
		//descending
		if(order_by == 0){
			//sort by id
			qsort(type1, type1_len, sizeof(struct inventory), cmpDesById);
			qsort(type2, type2_len, sizeof(struct inventory), cmpDesById);
			qsort(type3, type3_len, sizeof(struct inventory), cmpDesById);
		}
		else if(order_by == 1){
			//sort by price
			qsort(type1, type1_len, sizeof(struct inventory), cmpDesByPrice);
			qsort(type2, type2_len, sizeof(struct inventory), cmpDesByPrice);
			qsort(type3, type3_len, sizeof(struct inventory), cmpDesByPrice);
		}
	}
	else if(order == 1){
		//ascending
		if(order_by == 0){
			//sort by id
			qsort(type1, type1_len, sizeof(struct inventory), cmpAscById);
			qsort(type2, type2_len, sizeof(struct inventory), cmpAscById);
			qsort(type3, type3_len, sizeof(struct inventory), cmpAscById);
		}
		else if(order == 1){
			//sort by price
			qsort(type1, type1_len, sizeof(struct inventory), cmpAscByPrice);
			qsort(type2, type2_len, sizeof(struct inventory), cmpAscByPrice);
			qsort(type3, type3_len, sizeof(struct inventory), cmpAscByPrice);
		}
		
		printf("type 1:\n");
		printList(type1);
		printf("type2:\n");
		printList(type2);
		printf("type3:\n");
		printList(type3);
	}
	else{
		fprintf(stderr, "Wrong order_by parameter, please input 0 or 1\n");
	}

}

/***********************/
void deleteInv(int id){
}

void searchByID(int id){
}

void searchByName(char name[]){
}

/**********************/

int cmpDesById(const void *a, const void *b){

	int a_ID = ((struct inventory *)a)->id;
	int b_ID = ((struct inventory *)b)->id;

	return a_ID - b_ID;

}

int cmpAscById(const void *a, const void *b){

	int a_ID = ((struct inventory *)a)->id;
	int b_ID = ((struct inventory *)b)->id;

	return b_ID - a_ID;

}

int cmpDesByPrice(const void *a, const void *b){

	double a_price = ((struct inventory *)a)->price;
	double b_price = ((struct inventiry *)b)->price;

	if(a_price > b_price){
		return 1;
	}
	else if(a_price = b_price){
		return 0;
	}
	else{
		return -1;
	}
}

int cmpAscByPrice(const void *a, const void *b){

	double a_price = ((struct inventory *)a)->price;
	double b_price = ((struct inventiry *)b)->price;

	if(a_price > b_price){
		return -1;
	}
	else if(a_price = b_price){
		return 0;
	}
	else{
		return 1;
	}
}

void printList(struct inventory arr[]){
	int i;
	printf("id\tname\tprice\tquantity\n");//print title
	for(i = 0; i < arr.length; i++){
		printf("%d\t%s\t%f\t%d\n", arr[i].id, arr[i].name, arr[i].price, arr[i].quantity);
	}
}
