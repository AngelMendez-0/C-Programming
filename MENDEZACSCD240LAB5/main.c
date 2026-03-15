#include <stdio.h>
#include <stdlib.h>

int main() {
    int numInts, numChars, numFloats, numDoubles;

    printf("Enter number of integers: ");
    scanf("%d", &numInts);

    printf("Enter number of characters: ");
    scanf("%d", &numChars);

    printf("Enter number of floats: ");
    scanf("%d", &numFloats);

    printf("Enter number of doubles: ");
    scanf("%d", &numDoubles);

    int *intArray = (int *)malloc(numInts * sizeof(int));
    char *charArray = (char *)malloc(numChars * sizeof(char));
    float *floatArray = (float *)calloc(numFloats, sizeof(float));
    double *doubleArray = (double *)calloc(numDoubles, sizeof(double));

    if (intArray == NULL || charArray == NULL || floatArray == NULL || doubleArray == NULL) {
        printf("Memory allocation failed.\n");
        free(intArray);
        free(charArray);
        free(floatArray);
        free(doubleArray);
        return -1;
    } // end of if

    for (int i = 0; i < numInts; i++) {
        intArray[i] = i * 2;
    } // end of for

    for (int i = 0; i < numChars; i++) {
        charArray[i] = 'A' + (i % 26); // wrap around after 'Z'
    } // end of for

    for (int i = 0; i < numFloats; i++) {
        floatArray[i] = i + 0.5f;
    } // end of for

    for (int i = 0; i < numDoubles; i++) {
        doubleArray[i] = i * 1.11;
    } // end of for

    // Print arrays
    printf("Int array: ");
    for (int i = 0; i < numInts; i++) {
        printf("%d ", intArray[i]);
    } // end of for
    printf("\n");

    printf("Char array: ");
    for (int i = 0; i < numChars; i++) {
        printf("%c ", charArray[i]);
    } // end of for
    printf("\n");

    printf("Float array: ");
    for (int i = 0; i < numFloats; i++) {
        printf("%.1f ", floatArray[i]);
    } // end of for
    printf("\n");

    printf("Double array: ");
    for (int i = 0; i < numDoubles; i++) {
        printf("%.2lf ", doubleArray[i]);
    } // end of for
    printf("\n");

    free(intArray);
    free(charArray);
    free(floatArray);
    free(doubleArray);

    return 0;
} // end of main
