#include <stdio.h>
#include <stdlib.h>
#include "customer.h"

int main() {
    int bev; //variable inside switch back end exit
    int fev; //front end exit

    int st = 1;
    if (st){
        int inSt = 0;
        printf("Bank ATM System \n Enter 0 for login to the back end \n" "Enter 1 for front End \n");

        scanf("%d", &inSt);

        if (inSt != 1){

            printf("You are logged in to the Back end, Enter the number to do the relevant task \n");
            printf("1, Add New Customer \n");
            printf("2, List All Customers \n");
            printf("3, Modify Customers \n");


            int swcase;
            scanf("%d", &swcase);

            switch (swcase) {

                case 1 :
                    bev = 1;

                    while (bev){ //back End

                        int id;
                        char NIC[16];
                        long accNum;
                        char fname[100];
                        long dbtCardNum;
                        int dbtpin;
                        char branch[50];
                        float balance;

                        printf("Enter New Customer Information to the ATM \n");

                        puts("User ID");
                        scanf("%d", &id);
                        puts("National ID Card");
                        scanf("%s", &NIC);
                        puts("Account Number");
                        scanf("%ld", &accNum);
                        puts("Full Name");
                        scanf(" %[^\t\n]s",&fname);
                        puts("Debit Card Number");
                        scanf("%ld", &dbtCardNum);
                        puts("Debit Card PIN");
                        scanf("%d", &dbtpin);
                        puts("Branch");
                        scanf("%s", &branch);
                        puts("Balance");
                        scanf("%f", &balance);

                        addCustomer(id, NIC, accNum, fname, dbtCardNum, dbtpin, branch, balance);

                        printf("Do you want to add another Customer \n IF yes Insert 1, If not Insert 0 \n");
                        scanf("%d", &bev);

                    }
                    break;

                case 2:
                    printf("All the customers information");
                    readFile();

                    break;

                case 3:
                    printf("Enter the Customer NIC to Update details");
                    char moNIC[16];
                    scanf("%s", &moNIC);
                    if (modifyCusotmerFile(moNIC)){
                        bev = 1;

                        while (bev){ //back End

                            int id;
                            char NIC[16];
                            long accNum;
                            char fname[100];
                            long dbtCardNum;
                            int dbtpin;
                            char branch[50];
                            float balance;

                            printf("Update Customer Information \n");

                            puts("User ID");
                            scanf("%d", &id);
                            puts("National ID Card");
                            scanf("%s", &NIC);
                            puts("Account Number");
                            scanf("%ld", &accNum);
                            puts("Full Name");
                            scanf(" %[^\t\n]s",&fname);
                            puts("Debit Card Number");
                            scanf("%ld", &dbtCardNum);
                            puts("Debit Card PIN");
                            scanf("%d", &dbtpin);
                            puts("Branch");
                            scanf("%s", &branch);
                            puts("Balance");
                            scanf("%f", &balance);

                            modifyCustomer(id, NIC, accNum, fname, dbtCardNum, dbtpin, branch, balance);

                            printf("Do you want to update another Customer \n IF yes Insert 1, If not Insert 0 \n");
                            scanf("%d", &bev);

                        }
                    }
                    break;

                default:
                    printf("Wrong Input \n Exit...........");
            }

        } else {
            printf("Welcome to the *** ATM \n Please Enter your debit card \n");
            char dbcard[16];
            scanf("%s,", &dbcard);

            if (debitCardValid(dbcard) == 1){
                printf("Please Enter your PIN");
                char dbtPIN[6];
                //have to write code from here......

            } else {
                printf("Invalid Card / your card is not supported with this ATM network \n");
            }

        }

    }


    return 0;
}