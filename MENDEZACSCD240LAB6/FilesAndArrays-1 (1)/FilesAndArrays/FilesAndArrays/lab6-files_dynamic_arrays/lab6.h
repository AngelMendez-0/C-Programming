#ifndef LAB6_H
#define LAB6_H

#include <stdio.h>
#include <stdlib.h>

int menu();

int readDays(FILE * fin);

int * fillArray(int total, FILE * fin);

void displayMaxTemp(int * array, int total);

void displayMinTemp(int * array, int total);

void displayAvgTemp(int * array, int total);

void displayMedianTemp(int * array, int total);

void cleanUp(int * array);

void printArray(int * array, int total);

extern const int MAX;

#endif
