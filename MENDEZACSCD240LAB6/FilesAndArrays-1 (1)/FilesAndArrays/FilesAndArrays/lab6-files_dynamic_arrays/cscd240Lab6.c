#include "lab6.h"
#include "fileUtils.h"
#include "sortUtils.h"

const int MAX = 100;

int main(){

	int total, choice;
	int * temps = NULL;
	FILE * fin = NULL;
	char fn[MAX];

	readFileName(fn);
	fin = openInputFile(fn);

	if(fin == NULL) {
		printf("Failed to open file. Exiting.\n");
		return 1;

	} // end of if

	total = readDays(fin);
	temps = fillArray(total, fin);
	selectionSort(temps, total);
	printArray(temps, total);

	do{
		choice = menu();

		if(choice == 1) {
			displayMaxTemp(temps, total);

		} else if(choice == 2) {
			displayMinTemp(temps, total);

		} else if(choice == 3) {
			displayAvgTemp(temps, total);

		} else if(choice == 4) {
			displayMedianTemp(temps, total);

		} else if(choice == 6) {
			fclose(fin);
			fin = NULL;
			cleanUp(temps);
			temps = NULL;

			readFileName(fn);
			fin = openInputFile(fn);

			if(fin == NULL) {
				printf("Failed to open file. Exiting.\n");
				break;

			} // end of if

			total = readDays(fin);
			temps = fillArray(total, fin);
			selectionSort(temps, total);
			printArray(temps, total);

		} else if(choice == 7) {
			printf("Exiting program.\n");
			break;

		} // end of if

	} // end of do

	while(1);

	if(fin != NULL) fclose(fin);
	cleanUp(temps);
	temps = NULL;

	return 0;
} // end of main
