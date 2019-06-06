#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "filehandle.h"

struct customer{
    int userID;
    char NIC[20];
    long account_number;
    char full_name[100];
    long debit_cardNumber;
    int debit_cardPIN;
    char branch[50];
    float balance;

};

void addCustomer(int uID, char *NID, long acc_num, char *fname, long dbtCN, int dbtPIN, char *brch, float bal){
    struct customer COS;
    COS.userID = uID;
    strcpy(COS.NIC, NID);
    COS.account_number = acc_num;
    strcpy(COS.full_name, fname);
    COS.debit_cardNumber = dbtCN;
    COS.debit_cardPIN = dbtPIN;
    strcpy(COS.branch, brch);
    COS.balance = bal;

    char all[1000] = "";

    char sprUID[20];
    char spraACC[20];
    char sprDbtCN[16];
    char sprDbtPIN[6];
    char sprBal[10];

    sprintf(sprUID, "%d", COS.userID);
    sprintf(spraACC, "%ld", COS.account_number);
    sprintf(sprDbtCN, "%ld", COS.debit_cardNumber);
    sprintf(sprDbtPIN, "%d", COS.debit_cardPIN);
    sprintf(sprBal, "%f", COS.balance);

    strcat(all, sprUID); strcat(all, " , ");
    strcat(all, COS.NIC); strcat(all, " , ");
    strcat(all, spraACC); strcat(all, " , ");
    strcat(all, COS.full_name); strcat(all, " , ");
    strcat(all, sprDbtCN); strcat(all, " , ");
    strcat(all, sprDbtPIN); strcat(all, " , ");
    strcat(all, COS.branch); strcat(all, " , ");
    strcat(all, sprBal); strcat(all, " , ");

    puts(all);
    appendNewUser(all);
    printf("\n");

}

void modifyCustomer(int uID, char *NID, long acc_num, char *fname, long dbtCN, int dbtPIN, char *brch, float bal){
    struct customer COS;
    COS.userID = uID;
    strcpy(COS.NIC, NID);
    COS.account_number = acc_num;
    strcpy(COS.full_name, fname);
    COS.debit_cardNumber = dbtCN;
    COS.debit_cardPIN = dbtPIN;
    strcpy(COS.branch, brch);
    COS.balance = bal;

    char all[1000] = "";

    char sprUID[20];
    char spraACC[20];
    char sprDbtCN[16];
    char sprDbtPIN[6];
    char sprBal[10];

    sprintf(sprUID, "%d", COS.userID);
    sprintf(spraACC, "%ld", COS.account_number);
    sprintf(sprDbtCN, "%ld", COS.debit_cardNumber);
    sprintf(sprDbtPIN, "%d", COS.debit_cardPIN);
    sprintf(sprBal, "%f", COS.balance);

    strcat(all, sprUID); strcat(all, " , ");
    strcat(all, COS.NIC); strcat(all, " , ");
    strcat(all, spraACC); strcat(all, " , ");
    strcat(all, COS.full_name); strcat(all, " , ");
    strcat(all, sprDbtCN); strcat(all, " , ");
    strcat(all, sprDbtPIN); strcat(all, " , ");
    strcat(all, COS.branch); strcat(all, " , ");
    strcat(all, sprBal); strcat(all, " , ");

    puts(all);
    appendNewUser(all);
    printf("\n");

}