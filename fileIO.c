#include "fileIO.h"
#include "orderOperation.h"


/**/
int check_type(char *c_type)
{
    if      (!strcmp (c_type, "EDU"))   return EDU;
    else if (!strcmp (c_type, "FIN"))   return FIN;
    else if (!strcmp (c_type,"NOVEL"))  return NOVEL;
    //ERROR : type is not in the category list.
    else  return -1;
}
/**/
void readInv(void)
{
    int input;
    printf("Which type of data you want to input?\n");
    printf("[0] File or [1] Manual entry: ");
    scanf("%d", &input);

    //input a file
    if(input == 0)
    {
		const char path[100];
        printf("File path: ");
        scanf("%s", path);

		//testing path: "C:\Users\phoebe\Documents\testing.csv"
        FILE* fp = fopen(path, "r");
		
		if (!fp)
		{
			printf("Can't open file\n");
		}
    	else 
		{
			char *name, *c_type;
			int price, quantity, type;
        
        	// Here we have taken size of
        	// array 1024 you can modify it
        	char buffer[1024];
        	int row = 0;

        	/*problem : how to deal with syntax errors in the file?*/
        	while(fgets(buffer, 1024, fp)) 
			{
           		row++;
 
            	// To avoid getting the column
            	// names in file can be changed
            	// according to need
            	if (row == 1) continue;

            	// Splitting the data
            	char* value = strtok(buffer, ", \n");

            	// Column 1 : Name
            	name = value;
            	value = strtok(NULL, ", \n");

            	// Column 2 : Price
            	price = atoi(value);    /*problem : if atoi() return error value.*/
            	value = strtok(NULL, ", \n");

            	// Column 3 : Quantity
            	quantity = atoi(value); /*problem : if atoi() return error value.*/
            	value = strtok(NULL, ", \n");

            	// Column 4 : Type
            	c_type = value;
                type = check_type(c_type);

                if(value == NULL)
                {
                    //there are at least one value lost.
                    printf("ERROR : Line %d has missing value.\n", row);
                    break;
                }
                if(type == -1)
                {
                    //the type value is not in the list of category.        
                    printf("ERROR : The type attribute on line %d is incorrect\n", row);
                    break;
                }
                addInv(name,price,quantity,type);
			}
        // Close the file
        fclose(fp);
		}
    }
    //input one data
    else if(input == 1)
    {
		char name[20],c_type[20];
    	int price, quantity, type;
        
        printf("Name: ");
        scanf("%s", name);

        printf("Price: ");
        scanf("%d", &price);

        printf("Quantity: ");
        scanf("%d", &quantity);

        printf("Type: ");
        scanf("%s", c_type);
        type = check_type(c_type);

        if(type == -1)
        {
            //the type value is not in the list of category.        
            printf("ERROR : The type attribute is incorrect\n");
            return;
        }
        addInv(name,price,quantity,type);
    }
}

void printInv(void)
{
    int order, order_by;
    printf("To show the data, which attribute do you want to sort?\n");
    printf("[0] id or [1] price: ");
    scanf("%d", &order_by);
    printf("[0] increasing or [1] decreasing: ");
    scanf("%d", &order);
    sortInv(order,order_by);
    traversaInv();
}

void readOrder(void)
{
    int input;
    const char path[100];

    printf("Which type of data you want to input?\n");
    printf("[0] File or [1] Manual entry: ");
    scanf("%d", &input);

    if(input == 0)
    {
		const char path[100];
        printf("File path: ");
        scanf("%s", path);

		//testing path: "C:\\Users\\phoebe\\Documents\\testing_order.csv"
        //FILE* fp = fopen("testing_order.csv", "r");
        FILE* fp = fopen(path, "r");
		printf("%s\n",path);
		
		if (!fp)
		{
			printf("Can't open file\n");
		}
    	else 
		{
			char *CustomerName;
			int inventoryIds [5], inventoryQuantity [5], totalPrice;
        
        	// Here we have taken size of
        	// array 1024 you can modify it
        	char buffer[1024];
        	int row = 0;

        	while (fgets(buffer, 1024, fp)) 
			{
           		row++; 
            	// To avoid printing of column
            	// names in file can be changed
            	// according to need
            	if (row == 1) continue;

            	// Splitting the data
            	char* value = strtok(buffer, ", \n");

            	// Column 1 : Name
            	CustomerName = value;
            	value = strtok(NULL, ", \n");

                // Column 2~11 : item info
                for(int i = 0 ; i < 5 ; i++)
                {
                    // item i id
            	    inventoryIds [i] = atoi(value);
            	    value = strtok(NULL, ", \n");

            	    // item i  quantity
            	    inventoryQuantity [i] = atoi(value);
            	    value = strtok(NULL, ", \n");
                }

            	// Column 12 : totalPrice
            	totalPrice = atoi(value);

                if(value == NULL)
                {
                    // there are at least one value lost.
                    printf("ERROR : Line %d has missing value.\n", row);
                    break;
                }

                addOrder(CustomerName, inventoryIds, inventoryQuantity,totalPrice);
			}
        // Close the file
        fclose(fp);
		}
    }
    else if(input == 1)
    {
		char *CustomerName;
		int inventoryIds [5], inventoryQuantity [5], totalPrice;

        printf("CustomerName: ");
        scanf("%s", CustomerName);

        for(int i = 0 ;i < 5 ; i++)
        {
            printf("Product %d ID: ", i);
            scanf("%d", &inventoryIds[i]);

            printf("Product %d Amount: ", i);
            scanf("%d", &inventoryQuantity[i]);
        }

        printf("total price: ");
        scanf("%d", &totalPrice);

		//printf("%s\t%d\t%d\t%s\n",name, price, quantity, type);
        addOrder(CustomerName, inventoryIds, inventoryQuantity,totalPrice);
    }
}

void printOrder(void)
{
    int order, order_by;
    printf("To show the data, which attribute do you want to sort?\n");
    printf("[0] id or [1] total price: ");
    scanf("%d", &order_by);
    printf("[0] increasing or [1] decreasing: ");
    scanf("%d", &order);
    sortOrder(order,order_by);
}

void inventory()
{
    int action;
    while(true)
    {
        printf("Please enter an number to do with the inventory?\n");
        printf("[0] add [1] delete [2] show [3] search  [4] replenish [5] exit: ");
        scanf("%d", &action);

        if(action == 0)
        {
            static int InputType;
            printf("Which type of data to input? [0] file(.csv) [1] user input: \n");
            scanf("%d", &InputType);
            readInv();
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
            printInv();
        }
        else if(action == 3)
        {
            int search_by;
            int search_id;
            char search_name[MAX_BOOK_NAME];

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
        else if(action == 4)
        {
            int replenish_id;
            int replenish_num;
            printf("Enter the id you want to replenish?: ");
            scanf("%d",&replenish_id);
            searchInvByID(replenish_id);
            printf("Enter the amount of the book you want to add?: ");
            scanf("%d",&replenish_num);
            replenish(replenish_id,replenish_num);
        }
        else if(action == 5)
        {
            break;
        }
        else
        {
            printf("Please enter the correct value.\n");
        }
    }
}

void order()
{
    int action;
    while(true)
    {
        printf("Please enter an number to do with the order?\n");
        printf("[0] add [1] delete [2] show [3] search [4] exit:");
        scanf("%d", &action);
        
        if(action == 0)
        {
            static int InputType;
            printf("Which type of data to input? [0] file(.csv) [1] user input: \n");
            scanf("%d", &InputType);
            void readOrder();
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
                cancelOrder(id_del);
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
        else if(action == 4)
        {
            break;
        }
        else
        {
            printf("Please enter the correct value.\n");
        }
    }
}

void main_menu()
{
    int act_data;
    while(true)
    {
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
            break;
        }
        else{
            printf("Please enter the correct value.\n");
        }
    }
}


