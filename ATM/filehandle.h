//
// Created by shuja on 10/2/18 with JetBrains Clion on GNU/Linux.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 128
#define TOT 10

#define MAX 256

void modifications(){


}

void appendNewUser(char *usr){


    FILE *pFile2;
    char AllBuffer[1000];

    strcpy(AllBuffer, usr);

    pFile2=fopen("users.txt", "a");

    if(pFile2==NULL) {

        perror("Error opening file.\n");
    }

    else {
        fprintf(pFile2, AllBuffer);
        fprintf(pFile2,"\n", AllBuffer);

    }

    fclose(pFile2);

}

void readFile(){
    char line[TOT][BUF];
    FILE *plist = NULL;
    int i = 0;
    int total = 0;

    plist = fopen("users.txt", "r");
    while(fgets(line[i], BUF, plist)) {
        /* get rid of ending \n from fgets */
        line[i][strlen(line[i]) - 1] = '\0';
        i++;
    }

    total = i;

    for(i = 0; i < total; ++i){

        printf("%s\n", line[i]);

    }
    fclose(plist);
}

int debitCardValid(char dbcv){
    int ret = 0;

    char modAll[1000];
    char fidbcv[16];

    strcpy(fidbcv, dbcv);

    char line[TOT][BUF];
    FILE *plist = NULL;
    int i = 0;
    int total = 0;

    plist = fopen("users.txt", "r");
    while(fgets(line[i], BUF, plist)) {
        /* get rid of ending \n from fgets */
        line[i][strlen(line[i]) - 1] = '\0';
        i++;
    }

    total = i;

    for(i = 0; i < total; ++i){

        //printf("%s\n", line[i]);
        strcpy(modAll, line[i]);
        if(strstr(modAll, fidbcv) != NULL) {

            ret = 1;


        }
    }

    return ret;

};

int modifyCusotmerFile(char *nic){

    int ret = 0;

    char modAll[1000];
    char fiNIC[16];

    strcpy(fiNIC, nic);

    char line[TOT][BUF];
    FILE *plist = NULL;
    int i = 0;
    int total = 0;

    plist = fopen("users.txt", "r");
    while(fgets(line[i], BUF, plist)) {
        /* get rid of ending \n from fgets */
        line[i][strlen(line[i]) - 1] = '\0';
        i++;
    }

    total = i;

    for(i = 0; i < total; ++i){

        //printf("%s\n", line[i]);
        strcpy(modAll, line[i]);
        if(strstr(modAll, fiNIC) != NULL) {

            ret = 1;

            int lno, ctr = 0;
            char ch;
            FILE *fptr1, *fptr2;
            char fname[MAX];
            char str[MAX], temp[] = "temp.txt";
                //printf("\n\n Delete a specific line from a file :\n");
                //printf("-----------------------------------------\n");
                //printf(" Input the file name to be opened : ");
                //scanf("%s",fname);
            strcpy(fname, "users.txt");
            fptr1 = fopen(fname, "r");
            if (!fptr1) {
                    printf(" File not found or unable to open the input file!!\n");
                    return 0;
                }
            fptr2 = fopen(temp, "w"); // open the temporary file in write mode
            if (!fptr2){
                printf("Unable to open a temporary file to write!!\n");
                fclose(fptr1);
                return 0;

            }
                //printf(" Input the line you want to remove : ");
                //scanf("%d", &lno);
            lno = i;

            lno++;

                // copy all contents to the temporary file except the specific line
            while (!feof(fptr1)) {
                strcpy(str, "\0");
                fgets(str, MAX, fptr1);
                if (!feof(fptr1))
                 {
                    ctr++;
                        /* skip the line at given line number */
                        if (ctr != lno)
                        {
                            fprintf(fptr2, "%s", str);
                        }
                    }
                }
                fclose(fptr1);
                fclose(fptr2);
                remove(fname);  		// remove the original file
                rename(temp, fname); 	// rename the temporary file to original name

                    /*------ Read the file ----------------*/

                fptr1=fopen(fname,"r");
                ch=fgetc(fptr1);
                //printf(" Now the content of the file %s is : \n",fname);
                while(ch!=EOF)
                {
                    printf("%c",ch);
                    ch=fgetc(fptr1);
                }
                fclose(fptr1);
            // End of reading


        }
    }

    fclose(plist);

    return ret;

}