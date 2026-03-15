#include "lab7.h"
#include "fileUtils.h"

const int MAX = 100;

int main() {
	FILE * fin = NULL;
	int total, choice;
	Stock *array = NULL;

	fin = openInputFile();
	total = countRecords(fin, 3);
	rewind(fin);

	array = fillArray(fin, total);
	fclose(fin);

	do {
		choice = menu();
		switch(choice) {
			case 1:
				symbolSort(array, total);
				printArray(array, total);
				break;

			case 2:
				companySort(array, total);
				printArray(array, total);
				break;

			case 3:
				priceSort(total, array);
				printArray(array, total);
				break;

			case 4:
				printf("all done\n");
				break;
		} // end of switch

	} while(choice != 4);

	cleanUp(array, total);
	free(array);
	array = NULL;

	return 0;
} // end of main
