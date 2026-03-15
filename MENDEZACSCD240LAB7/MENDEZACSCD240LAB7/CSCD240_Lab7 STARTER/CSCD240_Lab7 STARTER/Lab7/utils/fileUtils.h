#ifndef FILEUTILS_H
#define FILEUTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXIMUM 100

void readFileName(char * fn);

FILE * openInputFile();

int countRecords(FILE * fin, const int linesPerRecord);

#endif
