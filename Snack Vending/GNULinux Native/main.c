#include <stdio.h>
#include <stdlib.h>
#include "items.h"
#include <string.h>


int main() {

    int back_ExitV; //back end handle
    int front_ExitV;

    int state = 1;

    if (state){

        int inner_State = 0;
        printf("FriMi - Snack Vending Machine \n Enter 0 for login to back end \n "
               "Enter 1 for login to front End \n");
        scanf("%d", &inner_State);

        if (inner_State != 1){

            printf("You are logged in to the back end, Enter the number to do the relevant task \n");
            printf("1 Add New Item \n");
            printf("2 List All Items \n");
            printf("3 Modify Items \n");
            printf("4 Delete Item \n");

            int switch_case;
            scanf("%d", &switch_case);

            switch (switch_case){

                case 1:
                    back_ExitV = 1;

                    while (back_ExitV){


                        int id;
                        char iname[50];
                        char catog[20];
                        int qqt;
                        float pri;

                        puts("Enter New Item to the System");

                        puts("Item ID");
                        scanf("%d", &id);
                        puts("Item Name");
                        scanf(" %[^\t\n]s", &iname);
                        puts("Category");
                        scanf(" %[^\t\n]s", &catog);
                        puts("Quantity");
                        scanf("%d", &qqt);
                        puts("Price");
                        scanf("%f", &pri);

                        addNewItem(id, iname, catog, qqt,pri);

                        printf("Do you want to Insert another new Item \n IF yes Insert 1, If not Insert 0 \n");
                        scanf("%d", &back_ExitV);


                    }

                    break; //case1 inner

                case 2:
                    puts("All Items with prices & available quantity");
                    puts("Item ID , Item Name , Category , Available QTY , Price");
                    readFile();

                    break;

                case 3:
                    puts("Update Item info using Item ID");
                    char upITM[16];
                    scanf("%s", &upITM);
                    char conCatID[16] = "id-";
                    strcat(conCatID, upITM); //concat id-1, id-2

                    if (modifyItemsFile(conCatID)){
                        back_ExitV = 1;
                        while (back_ExitV){
                            int id;
                            char iname[50];
                            char catog[20];
                            int qqt;
                            float pri;

                            puts("Enter New Item to the System");

                            puts("Item ID ");
                            scanf("%d", &id);
                            puts("Item Name");
                            scanf(" %[^\t\n]s", &iname);
                            puts("Category");
                            scanf(" %[^\t\n]s", &catog);
                            puts("Quantity");
                            scanf("%d", &qqt);
                            puts("Price");
                            scanf("%f", &pri);

                            addNewItem(id, iname, catog, qqt, pri);

                            printf("Do you want to update another Item's info? \n IF yes Insert 1, If not Insert 0 \n");
                            scanf("%d", &back_ExitV);
                        }
                    }

                    break;

                case 4:
                    puts("Delete Item info using Item ID");
                    char delITM[16];
                    scanf("%s", &delITM);
                    char DelconCatID[16] = "id-";
                    strcat(DelconCatID, delITM); //concat id-1, id-2

                    if (modifyItemsFile(DelconCatID)){
                        puts("Deleted");
                    } else{
                        puts("In valid ID");
                    }

                    break;

                default:
                    puts("Wrong Input");
                    break;
            }



        } else {
            front_ExitV = 1;
            while (front_ExitV){

                puts("Welcome to FriMi Snack Vendor \n");

                puts("Insert Number 1 For List All Items");
                puts("Insert Number 2 For get an item using item ID");

                int frontSw = 0;
                scanf("%d", &frontSw);

                int front_ExitV2 = 1;

                switch (frontSw) {
                    case 1:
                        while (front_ExitV2){
                            puts("All Items with prices & available quantity");
                            puts("Item ID , Item Name , Category , Available QTY , Price");
                            readFile();
                            printf("\n");
                            puts("Now Please Enter an Item ID");
                            char upITM[16];
                            scanf("%s", &upITM);
                            char conCatID[16] = "id-";
                            strcat(conCatID, upITM); //concat id-1, id-2
                            getItemQty(conCatID);





                        }
                        break;
                    default:
                        puts("Wrong Input");
                }

            }
        }


    }



    return 0;
}