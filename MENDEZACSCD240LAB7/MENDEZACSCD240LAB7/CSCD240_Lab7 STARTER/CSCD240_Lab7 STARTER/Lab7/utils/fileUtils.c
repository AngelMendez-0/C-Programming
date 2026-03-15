#include "fileUtils.h"
#include "utils.h"

void readFileName(char * fn) {
    printf("Please enter the name of the file ");
    fgets(fn, MAXIMUM, stdin);
    strip(fn);

} // end of readFileName

FILE * openInputFile() {
    char fn[MAXIMUM];
    FILE * inf = NULL;

    do {
        readFileName(fn);
        inf = fopen(fn, "r");
        if (inf == NULL){
            printf("File failed to open. Try again.\n");
        } // end of if
    }while
        (inf == NULL);

    return inf;
} // end of openInputFile

int countRecords(FILE * fin, const int linesPerRecord) {
    int count = 0;
    char temp[MAXIMUM];

    while (fgets(temp, MAXIMUM, fin) != NULL)
        count++;

    return count / linesPerRecord;
} // end of countRecords
