#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>



#define MAXSIZE 100


int main(){
    FILE *ifp;
    char filename[] = "CDBdatabase.txt";
    char choice[MAXSIZE] = "INIT";
    char item[MAXSIZE]; 
    double priceAndTax;
    double totalForDay = 0;
    int Quantity;
    ifp = fopen(filename, "a");

    time_t current_time = time(NULL);
    struct tm *tm = localtime(&current_time);


    while (strcmp(choice, "CLOSE") != 0){

        printf("*****************\n");
        printf("CBD SALES\nPLEASE PRINT IN ALL CAPS!\n");
        printf("FUNCTIONS INCLUDE:\nSALE REFUND AND CLOSEDAY\n");
        printf("*****************\n");
        scanf("%s", choice);

        if (strcmp(choice, "SALE") == 0){
            printf("Input Specified: Item Price+Tax QuanitySold\n");
            scanf("%s %lf %d", item, &priceAndTax, &Quantity);
            totalForDay = totalForDay + priceAndTax;
            fprintf(ifp, "%s %s %lf %d\n", choice, item, priceAndTax, Quantity);
        }
        else if (strcmp(choice, "REFUND") == 0){
            printf("Input Specified: Item Price+Tax QuanitySold\n");
            scanf("%s %lf %d", item, &priceAndTax, &Quantity);
            totalForDay = totalForDay - (priceAndTax);
            fprintf(ifp, "%s %s %lf %d\n", choice, item, -priceAndTax, -Quantity);
        }
        else if (strcmp(choice, "CLOSEDAY") == 0){
            fprintf(ifp,"Close for the day\nTotal for day = %lf\n%s\n", totalForDay, asctime(tm));
            strcpy(choice, "CLOSE");
        }
    }
    


    fclose(ifp);
    return 0;
}

