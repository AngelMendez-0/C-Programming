#ifndef LAB7_H
#define LAB7_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stock{
   char *symbol;

   char *name;

   double price;
} Stock;

Stock * fillArray(FILE * fin, int total);

int menu();

void symbolSort(Stock array[], int total);

void companySort(Stock array[], int total);

void priceSort(int total, Stock array[]);

void printArray(Stock array[], int total);

void cleanUp(Stock * array, int total);

#endif
