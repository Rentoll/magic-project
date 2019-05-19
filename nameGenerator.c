#include <string.h>
#include <time.h>
#include <stdio.h>
#include "nameGenerator.h"


void generateName(char *first) {
    FILE *fileWithNames = fopen ("names.txt", "r");
    freopen ("names.txt", "r", fileWithNames);
    char tempArr[150];
    int nameNumber = rand()%20;
    int temp = 0;
    while(temp < nameNumber) {
        fgets(tempArr, 149, fileWithNames);
        temp++;
    }
    fgets(tempArr, 149, fileWithNames);
    strcpy(first, tempArr);
    fclose(fileWithNames);
}



