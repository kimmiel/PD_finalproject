#include "fileIO.h"

void inventory(){
    int action;
    while(true){
        printf("Please enter an number to do with the inventory?\n");
        printf("[0] add [1] delete [2] show [3] search  [4] replenish [5] exit: ");
        scanf("%d", &action);

        if(action == 0)
        {
            static int InputType;
            printf("Which type of data to input? [0] file(.csv) [1] user input: \n");
            scanf("%d", &InputType);
            //not finish
        }
        else if(action == 1)
        {
            int num_del;
            int id_del;
            printf("Enter the number of data you want to delete?: ");
            scanf("%d", &num_del);
            for(int i = 0 ; i < num_del ; i++)
            {
                printf("Enter the %d's book id to detete: ",i);
                scanf("%d",&id_del);
                deleteInv(id_del);
            }
        }
        else if(action == 2)
        {
            //problem: how to do with the input is in the list correct.
            int order, order_by;
            printf("To show the data, which attribute do you want to sort?\n");
            printf("[0] id or [1] price: ");
            scanf("%d", &order_by);
            printf("[0] increasing or [1] decreasing: ");
            scanf("%d", &order);
            sortInv(order,order_by);
            traversaInv();
        }
        else if(action == 3)
        {
            int search_by;
            int search_id;
            char search_name[NAME_SIZE];

            printf("Which attribute you want to search with?\n");
            printf("[0] id or [1] name: ");
            scanf("%d", &search_by);
            if(search_by == 0)
            {
                printf("Enter the book id: ");
                scanf("%d",&search_id);
                searchInvByID(search_id);
            }
            else if(search_by == 1)
            {
                printf("Enter the book name: ");
                scanf("%s",search_name);
                searchInvByName(search_name);
            }
            else
            {
                printf("Please enter the correct number.\n");
            }
        }
        else if(action == 4){
            int replenish_id;
            int replenish_num;
            printf("Enter the id you want to replenish?: ");
            scanf("%d",&replenish_id);
            searchInvByID(replenish_id);
            printf("Enter the amount of the book you want to add?: ");
            scanf("%d",&replenish_num);
            replenish(replenish_id,replenish_num);
        }
        else if(action == 5){
            return;
        }
        else{
            printf("Please enter the correct value.\n");
        }
    }
}
void order(){
    int action;
    while(true){
        printf("Please enter an number to do with the order?\n");
        printf("[0] add [1] delete [2] show [3] search [4] exit:");
        scanf("%d", &action);
        
        if(action == 0)
        {
            static int InputType;
            printf("Which type of data to input? [0] file(.csv) [1] user input: \n");
            scanf("%d", &InputType);
            //not finish
        }
        else if(action == 1)
        {
            int num_del;
            int id_del;
            printf("How many number of data do you want to delete?: ");
            scanf("%d", &num_del);
            for(int i = 0 ; i < num_del ; i++){
                printf("Enter the %d's order id to detete: ",i);
                scanf("%d",&id_del);
                deleteOrder(id_del);
            }
        }
        else if(action == 2)
        {
            //problem: how to do with the input is in the list correct.
            int order, order_by;
            printf("To show the data, which attribute do you want to sort?");
            printf("[0] id or [1] total amount: ");
            scanf("%d", &order_by);
            printf("[0] increasing or [1] decreasing: ");
            scanf("%d", &order);
            sortOrder(order,order_by);
        }
        else if(action == 3)
        {    
            int search_id;
            printf("Enter the order id to search: ");
            scanf("%d",&search_id);
            searchOrder(search_id);
            
        }
        else if(action == 4){
            return;
        }
        else{
            printf("Please enter the correct value.\n");
        }
    }
}

void main_menu(){
    int act_data;
    while(true){

        printf("Which data do you want to act on ?\n");
        printf("[0] inventory [1] order [2] Quit: ");
        scanf("%d", &act_data);

        if(act_data == 0){
            inventory();
        }
        else if(act_data == 1){
            order();
        }
        else if(act_data == 2){
            return;
        }
        else{
            printf("Please enter the correct value.\n");
        }
    }

}

void readInv(void);
void printInv(void);
void mainMenu(void);
void readOrder(void);
void printOrder(void);
