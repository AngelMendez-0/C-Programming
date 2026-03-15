#include "lab7.h"
#include "utils.h"

int menu() {
    int num;
    do {
        printf("Please choose from the following\n");
        printf("1) Sort by Symbol\n");
        printf("2) Sort by Company Name\n");
        printf("3) Sort by Price\n");
        printf("4) Quit\n");
        printf("Choice --> ");
        scanf("%d", &num);
        while(fgetc(stdin) != '\n');
    } while(num < 1 || num > 4);

    return num;
} // end of menu

Stock * fillArray(FILE * fin, int total) {
    int x;
    char temp[100];
    Stock * array = (Stock *)calloc(total, sizeof(Stock));

    for (x = 0; x < total; x++){
        fgets(temp, 100, fin);
        strip(temp);
        array[x].symbol = strdup(temp);

        fgets(temp, 100, fin);
        strip(temp);
        array[x].name = strdup(temp);

        fgets(temp, 100, fin);
        strip(temp);
        array[x].price = atof(temp);
    } // end of for

    return array;
} // end of fillArray

void printArray(Stock array[], int total) {
    for(int x = 0; x < total; x++){
        printf("%s - %s - $%.2lf\n\n", array[x].name, array[x].symbol, array[x].price);
    } // end of for
} // end of printArray

void symbolSort(Stock array[], int total) {

    for(int i = 0; i < total - 1; i++) {
        int min = i;

        for(int j = i + 1; j < total; j++){
            if(strcmp(array[j].symbol, array[min].symbol) < 0)
                min = j;
        } // end of for

        if(min != i) {
            Stock temp = array[i];
            array[i] = array[min];
            array[min] = temp;

        } // end of if

    } // end of for
} // end of symbolSort

void companySort(Stock array[], int total) {

    for(int i = 0; i < total - 1; i++) {
        int min = i;

        for(int j = i + 1; j < total; j++) {
            if(strcmp(array[j].name, array[min].name) < 0)
                min = j;
        } // end of for

        if(min != i) {
            Stock temp = array[i];
            array[i] = array[min];
            array[min] = temp;
        } // end of if
    } // end of for
} // end of companySort

void priceSort(int total, Stock array[]) {

    for(int i = 0; i < total - 1; i++) {
        int min = i;

        for(int j = i + 1; j < total; j++) {
            if(array[j].price < array[min].price)
                min = j;
        } // end of for

        if(min != i) {
            Stock temp = array[i];
            array[i] = array[min];
            array[min] = temp;

        } // end of if

    } // end of for
} // end of priceSort

void cleanUp(Stock * array, int total){
    for(int x = 0; x < total; x++) {
        free(array[x].symbol);
        free(array[x].name);
    } // end of for
} // end of cleanup
