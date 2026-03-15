#include "fileUtils.h"

void readFileName(char * fn) {
	printf("Enter the filename: ");
	if (fgets(fn, 256, stdin) != NULL){
		strip(fn);
	} // end of if

} // end of readFileName

FILE * openInputFile(char * fn) {
	FILE * file = fopen(fn, "r");

	if (file == NULL) {
		printf("Error opening file '%s'. Please check the filename and try again.\n", fn);

	} // end of if

	return file;

} // end of openInputFile

void strip(char * array) {
	int len = strlen(array);
	while (len > 0 && (array[len - 1] == '\n' || array[len - 1] == '\r' || array[len - 1] == ' ' || array[len - 1] == '\t')){
		array[len - 1] = '\0';
		len--;

	} // end of while

} // end of strip
