#include "lab6.h"

extern const int MAX;

int menu() {
    int choice;
    do {
        printf("Please enter a menu choice\n");
        printf("1) Display Max Temp\n");
        printf("2) Display Min Temp\n");
        printf("3) Display Average Temp\n");
        printf("4) Display Median Temp\n");
        printf("6) Load a new file\n");
        printf("7) Quit\n");
        printf("Choice --> ");
        scanf("%d", &choice);
        while(getchar() != '\n'); // clear input buffer
    } // end of do

    while(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 6 && choice != 7);

    return choice;
} // end of menu

int readDays(FILE * fin) {

    int total = 0;
    if (fin == NULL) return 0;

    fscanf(fin, "%d", &total);
    return total;

} // end of readDays

int * fillArray(int total, FILE * fin) {
    if (fin == NULL || total <= 0) return NULL;

    int * temp = malloc(sizeof(int) * total);

    if (temp == NULL){
        printf("Memory allocation failed.\n");
        return NULL;

    } // end of if

    for (int i = 0; i < total; i++){

        if (fscanf(fin, "%d", &temp[i]) != 1) {
            printf("Error reading temperature data from file.\n");
            free(temp);
            return NULL;

        } // end of if

    } // end of for

    return temp;

} // end of fillArray

void displayMaxTemp(int * array, int total) {

    if (array == NULL || total <= 0) return;

    int max = array[0];

    for (int i = 1; i < total; i++) {
        if (array[i] > max)
            max = array[i];
    } // end of for

    printf("Maximum Temperature: %d\n", max);

} // end of displayMaxTemp

void displayMinTemp(int * array, int total) {

    if (array == NULL || total <= 0) return;

    int min = array[0];
    for (int i = 1; i < total; i++){
        if (array[i] < min)
            min = array[i];
    } // end of for

    printf("Minimum Temperature: %d\n", min);

} // end of displayMinTemp

void displayAvgTemp(int * array, int total) {
    if (array == NULL || total <= 0) return;

    int sum = 0;
    for (int i = 0; i < total; i++)
        sum += array[i];

    double avg = (double)sum / total;
    printf("Average Temperature: %.2f\n", avg);

} // end of displayAVG temp

void displayMedianTemp(int * array, int total) {

    if (array == NULL || total <= 0) return;

    double median;
    if (total % 2 == 1){
        median = array[total / 2];

    } else {
        median = (array[(total / 2) - 1] + array[total / 2]) / 2.0;

    } // end of if


    printf("Median Temperature: %.2f\n", median);
} // end of displayMedianTemp

void cleanUp(int * array) {
    if (array != NULL)
        free(array);

} // end of cleanUp

void printArray(int * array, int total) {
    if (array == NULL || total <= 0){
        printf("Array is empty.\n");
        return;

    } // end of if

    printf("[");

    for (int x = 0; x < total - 1; x++)
        printf("%d, ", array[x]);

    printf("%d]\n", array[total - 1]);

} // end of printArray
