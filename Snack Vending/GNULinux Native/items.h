//
// Created by shuja on 10/2/18.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "filehandle.h"

struct items{
    int itemID;
    char item_name[50];
    char category[20];
    int qty;
    float item_price;

};

void addNewItem(int itID, char *itname, char *catog, int q, float pri){

    struct items ITM;
    ITM.itemID = itID;
    strcpy(ITM.item_name, itname);
    strcpy(ITM.category, catog);
    ITM.qty = q;
    ITM.item_price = pri;

    char all[500] = "";

    char strItemID[10];
    char strQty[50];
    char strPrice[10];

    char finalID[10] = "id-";  //to concatnate befor ID number

    sprintf(strItemID, "%d", ITM.itemID);
    sprintf(strQty, "%d", ITM.qty);
    sprintf(strPrice, "%f", ITM.item_price);

    char QS[100];
    char strgs[150];
    strcpy(QS,"QTY: ");
    strcat(QS,strQty);

    strcat(finalID, strItemID); //final ID looks like id-1, id-2

    strcat(all, finalID); strcat(all, " , ");
    strcat(all, ITM.item_name); strcat(all, " , ");
    strcat(all, ITM.category); strcat(all, " , ");

    strcat(all, QS); strcat(all, " , ");
    strcat(all, strPrice); strcat(all, " , ");

    puts(all);
    appendNewItem(all);
    printf("\n");

}

void getItemQty(char *ii){
    int a = getItemQtyFromFile(ii);
    printf("%d \n, Items Available ", ikl);

}
